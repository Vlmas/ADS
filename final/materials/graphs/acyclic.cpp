#include<iostream>
#include<vector>

using namespace std;

vector<int> g[100];

int used[100];
int n,m,x,y;

void dfs(int v) {
    if(used[v]==1) {
        cout<<"Given graph has cycles";
        exit(0);
    }
    used[v]=1;

    for(int i=0;i<g[v].size();i++) {
        if(!used[g[v][i]]) {
            dfs(g[v][i]);
        }
        // else if(used[g[v][i]]==1) {
        //     cout<<"Given graph has cycles";
        //     exit(0);
        // }
    }
    used[v]=2;
}

int main() {
    cin>>n>>m;

    for(int i=0;i<m;i++) {
        cin>>x>>y;

        x--; y--;

        g[x].push_back(y);
        // g[y].push_back(x);
    }

    for(int i=0;i<n;i++) {
        if(!used[i]) {
            dfs(i);
        }
    }
    cout<<"Given graph is acyclic";


    return 0;
}