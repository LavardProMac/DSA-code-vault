#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j, e=n; i<=e; ++i)
using namespace std;
const int N=505;

int n, m, a[N][N];
int lg[N], st[10][10][N][N];

void build(){
    fo(i,2,max(n,m)) lg[i]=lg[i>>1]+1;
    fo(i,1,n) fo(j,1,m) st[0][0][i][j]=a[i][j];

    fo(x,0,lg[n]) fo(y,0,lg[m]){
        if(!x && !y) continue;
        
        fo(i,1,n-(1<<x)+1) fo(j,1,m-(1<<y)+1)
            st[x][y][i][j]=x?
            min(st[x-1][y][i][j], st[x-1][y][i+(1<<x-1)][j]):
            min(st[x][y-1][i][j], st[x][y-1][i][j+(1<<y-1)]);
    }
}

inline int get(int x1, int y1, int x2, int y2){
    int kx=lg[x2-x1+1], ky=lg[y2-y1+1],
        dx=x2-(1<<kx)+1, dy=y2-(1<<ky)+1;

    return min({st[kx][ky][x1][y1], st[kx][ky][dx][y1],
                st[kx][ky][x1][dy], st[kx][ky][dx][dy]});
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    fo(i,1,n) fo(j,1,m) cin>>a[i][j];
    
    build();
    int q, x1, y1, x2, y2; cin>>q;
    
    while(q--)
        cin>>x1>>y1>>x2>>y2,
        cout<<get(x1, y1, x2, y2)<<'\n';
}
