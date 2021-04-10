#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int used[100][100];
int d[100][100];

queue<pair<int,int> > q;
vector<pair<int,int> > g;

int dx[]={-1,1,2,2,1,-1,-2,-2};
int dy[]={2,2,1,-1,-2,-2,-1,1};

int x0,y0,x1,y1,n;

bool inBorder(int x,int y) {
    return (x<n && x>=0 && y<n && y>=0);
}

vector<pair<int,int> > fillPath(int x,int y) {
    vector<pair<int,int> > res;
    int tx,ty;

    while(true) {
        res.push_back(make_pair(x,y));

        if (d[x][y]==0) {
            break;
        }

        for(int i=0;i<8;i++) {
            tx=x+dx[i]; ty=y+dy[i];

            if (inBorder(tx,ty)) {
                if (d[x][y]-1==d[x+dx[i]][y+dy[i]]) {
                    x+=dx[i];
                    y+=dy[i];
                    break;
                }
            }
        }
    }

    return res;
}

void bfs(int x,int y) {
    q.push(make_pair(x,y));
    used[x][y]=1;
    d[x][y]=0;

    g.push_back(make_pair(x,y));

    int tx,ty;

    while(!q.empty()) {
        for(int i=0;i<8;i++) {
            tx=q.front().first+dx[i]; ty=q.front().second+dy[i];

            if(!used[tx][ty] && inBorder(tx,ty)) {
                used[tx][ty]=1;
                d[tx][ty]=d[q.front().first][q.front().second]+1;
                q.push(make_pair(tx,ty));
                g.push_back(make_pair(tx,ty));
            }
        }
        q.pop();
    }
}

int main() {
    cin>>n>>x0>>y0>>x1>>y1;

    x0--; y0--; x1--; y1--;

    bfs(x0,y0);
    g=fillPath(x1,y1);
    reverse(g.begin(),g.end());

    cout<<d[x1][y1]<<"\n";

    for(auto i : g) {
        cout<<i.first+1<<" "<<i.second+1<<"\n";
    }


    return 0;
}