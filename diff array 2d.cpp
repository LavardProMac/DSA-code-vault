// Source: hnoj.edu.vn/problem/t6nano

#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll, int>
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
int d[1005][1005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int m, n, q; cin>>m>>n>>q;
    int k=m*n, a[k+1], v[k+1], t=0;

    fo(i,1,k) cin>>a[i];
    sort(a+1, a+k+1, greater<int>());

    while(q--){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        ++d[x1][y1]; --d[x2+1][y1];
        --d[x1][y2+1]; ++d[x2+1][y2+1];
    }
    fo(i,1,m) fo(j,2,n) d[i][j]+=d[i][j-1];
    fo(j,1,n) fo(i,2,m) d[i][j]+=d[i-1][j];

    fo(i,1,m) fo(j,1,n) v[++t]=d[i][j];
    sort(v+1, v+k+1); ll ans=0;

    fo(i,1,k) ans+=1ll*v[i]*a[i];
    cout<<ans;
}
