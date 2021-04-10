#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> g[100];
vector<int> res;

int used[100];
int n,m,x,y;

void topSort(int v) {
    used[v]=1;

    for(int i=0;i<g[v].size();i++) {
        if(!used[g[v][i]]) {
            topSort(g[v][i]);
        }
    }
    res.push_back(v);
}

int main() {
    cin>>n>>m;

    for(int i=0;i<m;i++) {
        cin>>x>>y;

        x--; y--;

        g[x].push_back(y);
    }

    for(int i=0;i<n;i++) {
        if(!used[i]) {
            topSort(i);
        }
    }

    reverse(res.begin(),res.end());

    for(auto& i : res) {
        cout<<i+1<<" ";
    }
    


    return 0;
}