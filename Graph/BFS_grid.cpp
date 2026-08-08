#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int m, n;
char a[105][105];
bitset<105> vs[105];

int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, -1, 1};

void bfs(int sx, int sy){
    queue<pair<int, int>> q;
    q.push({sx, sy}); vs[sx][sy]=1;

    while(!q.empty()){
        auto [x, y]=q.front(); q.pop();
        fo(k,0,3){
            int u=x+dx[k], v=y+dy[k];
            if(u<1 || u>m || v<1 || v>n) continue;
            if(vs[u][v] || a[u][v]=='*') continue;
            vs[u][v]=1; q.push({u, v});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>m>>n;
    fo(i,1,m) fo(j,1,n) cin>>a[i][j];

    fo(i,1,m) fo(j,1,n)
        if(a[i][j]!='*' && !vs[i][j])
            bfs(i, j);
}
