#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int g[1000][1000];
int used[1000][1000];
int d[1000][1000];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int n,m,ax,ay;

queue<pair<int,int> > q;

bool correct=true;

bool inBorder(int x,int y) {
    return (x>=0 && x<n && y>=0 && y<m);
}

void bfs() {
    int tx,ty,xx,yy;

    while(!q.empty()) {
        xx=q.front().first; yy=q.front().second;

        for(int i=0;i<4;i++) {
            tx=xx+dx[i]; ty=yy+dy[i];

            if(inBorder(tx,ty) && !used[tx][ty] && g[tx][ty]==1) {
                q.push(make_pair(tx,ty));
                used[tx][ty]=1;
                d[tx][ty]=d[xx][yy]+1;
                ax=tx; ay=ty;
                g[tx][ty]=2;
            }
        }
        q.pop();
    }
}

int main() {
    cin>>n>>m;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>g[i][j];

            if(g[i][j]==2) {
                q.push(make_pair(i,j));
                used[i][j]=1;
                d[i][j]=0;
            }
        }
    }

    bfs();

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!used[i][j] && g[i][j]==1) {
                correct=false;
            }
        }
    }
    
    if(correct) {
        cout<<d[ax][ay];
    } else {
        cout<<-1;
    }


    return 0;
}