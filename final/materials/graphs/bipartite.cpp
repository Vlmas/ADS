#include<iostream>
#include<vector>

using namespace std;

vector<int> g[100];
int used[100];

int n,m,x,y;
bool ok;

void dfs(int v,int c) {
    used[v]=c;

    for(int i=0;i<g[v].size();i++) {
        if(!used[g[v][i]]) {
            dfs(g[v][i],3-c);
        } else {
            if(used[g[v][i]]==c) {
                ok=false;
            }
        }
    }
}

int main() {    
    cin>>n>>m;

    for(int i=0;i<m;i++) {
        cin>>x>>y;

        x--; y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    ok=true;

    for(int i=0;i<n;i++) {
        if(!used[i]) {
            dfs(i,1);
        }
    }

    string res=(ok)?"YES":"NO";
    cout<<res;

    return 0;
}