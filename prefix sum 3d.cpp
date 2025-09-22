#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int x, y, z, q; cin>>x>>y>>z;
    ll a[x+1][y+1][z+1], p[x+1][y+1][z+1];
    memset(p, 0, sizeof(p));
    fo(k,1,z) fo(j,1,y) fo(i,1,x)
        cin>>a[i][j][k];
    fo(k,1,z) fo(j,1,y) fo(i,1,x)
        p[i][j][k]=p[i-1][j][k]+p[i][j-1][k]+
        p[i][j][k-1]-p[i-1][j-1][k]-
        p[i][j-1][k-1]-p[i-1][j][k-1]+
        p[i-1][j-1][k-1]+a[i][j][k];
    int x1, y1, z1, x2, y2, z2; cin>>q;
    while(q--)
        cin>>x1>>y1>>z1>>x2>>y2>>z2,
        cout<<p[x2][y2][z2]-p[x1-1][y2][z2]-
        p[x2][y1-1][z2]-p[x2][y2][z1-1]+
        p[x1-1][y1-1][z2]+p[x1-1][y2][z1-1]+
        p[x2][y1-1][z1-1]-
        p[x1-1][y1-1][z1-1]<<'\n';
}
