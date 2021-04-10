#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> g[100];
queue<int> q;

int used[100];
int d[100];
int n,m,x,y;

void bfs(int x) {
    q.push(x);
    used[x]=1;
    d[x]=0;

    while(!q.empty()) {
        int v=q.front();

        for(int i=0;i<g[v].size();i++) {
            if(!used[g[v][i]]) {
                used[g[v][i]]=1;
                d[g[v][i]]=d[v]+1;
                q.push(g[v][i]);
            }
        }

        q.pop();
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

    bfs(0);

    for(int i=0;i<n;i++) {
        cout<<i+1<<" "<<d[i]<<"\n";
    }

    


    return 0;
}