// Source: cses.fi/problemset/task/1193

#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=l; i<=r; i++)
using namespace std;
const int N=1001;

char a[N][N], tr[N][N]; bool vs[N][N];
int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, -1, 1};
char dc[]={'U', 'D', 'L', 'R'};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, sx, sy, tx, ty;
    cin>>n>>m; 

    fo(i,1,n) fo(j,1,m){
        cin>>a[i][j];
        if(a[i][j]=='A') sx=i, sy=j;
        else if(a[i][j]=='B') tx=i, ty=j;
    }
    queue<pair<int, int>> q;
    vs[sx][sy]=1; q.push({sx, sy});

    while(!q.empty()){
        auto [x,y]=q.front(); q.pop();
        fo(i,0,3){
            int u=x+dx[i], v=y+dy[i];

            if(u<1 || u>n || v<1 || v>m)
                continue;
            if(vs[u][v] || a[u][v]=='#')
                continue;

            vs[u][v]=1; tr[u][v]=dc[i];
            q.push({u, v});
        }
    }
    if(!vs[tx][ty]) return cout<<"NO", 0;
    cout<<"YES\n"; string s;

    while(tx!=sx || ty!=sy){
        char c=tr[tx][ty];
        s.push_back(c);

        if(c=='U') ++tx;
        else if(c=='D') --tx;
        else if(c=='L') ++ty;
        else --ty;
    }
    reverse(s.begin(), s.end());
    cout<<s.size()<<'\n'<<s;
}
