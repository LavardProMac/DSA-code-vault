// Source: cses.fi/problemset/task/1192

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
 
int n, m; char a[1001][1001];
int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, -1, 1};
 
void dfs(int x, int y){
    a[x][y]='#';
    fo(i,0,3){
        int u=x+dx[i], v=y+dy[i];
        if(u<1 || u>n || v<1 || v>m || a[u][v]=='#')
            continue;
        dfs(u, v);
    }
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int ans=0; cin>>n>>m;
    fo(i,1,n) fo(j,1,m) cin>>a[i][j];
    
    fo(i,1,n) fo(j,1,m) if(a[i][j]=='.')
        ++ans, dfs(i, j);
    cout<<ans;
}
