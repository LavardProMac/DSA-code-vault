#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
ll p[1001][1001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, x, x1, y1, x2, y2; cin>>n>>q;
    
    fo(i,1,n) fo(j,1,n) cin>>x,
        p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+x;
    
    while(q--) cin>>x1>>y1>>x2>>y2,
        cout<<p[x2][y2]-p[x2][y1-1]-p[x1-1][y2]+p[x1-1][y1-1]<<'\n';
}
