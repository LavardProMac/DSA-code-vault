// Source: hnoj.edu.vn/problem/d4pikachu

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=105;

int m, n, ans; char a[N][N];
int d[N][N], v[N][N], id;

int dx[]={-1, 1, 0, 0};
int dy[]={0,0, -1, 1};

void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j}); d[i][j]=0;
    v[i][j]=++id;

    while(!q.empty()){
        auto [r, c]=q.front(); q.pop();
        if(d[r][c]==3) continue;

        fo(t,0,3){
            int x=r+dx[t], y=c+dy[t];
            while(x>=0 && x<=m+1 && y>=0 && y<=n+1){
                if(a[x][y]==a[i][j]){
                    if((x>i || x==i && y>j) && v[x][y]!=id)
                        v[x][y]=id, ++ans;
                    break;
                }
                if(a[x][y]!='.') break;

                if(v[x][y]!=id || d[x][y]>d[r][c]+1)
                    v[x][y]=id,
                    d[x][y]=d[r][c]+1,
                    q.push({x, y});

                x+=dx[t]; y+=dy[t];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>m>>n;

    fo(i,0,m+1) fo(j,0,n+1) a[i][j]='.';
    fo(i,1,m) fo(j,1,n) cin>>a[i][j];

    fo(i,1,m) fo(j,1,n)
        if(a[i][j]!='.') bfs(i, j);
    cout<<ans;
}
