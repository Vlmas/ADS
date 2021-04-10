#include<iostream>
#include<vector>

using namespace std;

vector<int> g[100];

int used[100];
int n,m,x,y;

void dfs(int v) {
    used[v]=1;

    for(int i=0;i<g[v].size();i++) {
        if(!used[g[v][i]]) {
            dfs(g[v][i]);
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

    int cnt=0;

    for(int i=0;i<n;i++) {
        if(!used[i]) {
            dfs(i);
            cnt++;
        }
    }

    cout<<cnt;
    


    return 0;
}