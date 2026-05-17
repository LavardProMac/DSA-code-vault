// Đề: đếm số đoạn con có max - min <= k
// Source: creativecode.vn/problem/subdiff

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j, e=n; i<=e; ++i)
using namespace std;

const int N=2e5+5;
int n, a[N], lg[N], mx[18][N], mi[18][N];

void build(){
    mx[0][1]=mi[0][1]=a[1];
    fo(i,2,n) lg[i]=lg[i>>1]+1,
        mx[0][i]=mi[0][i]=a[i];
    
    fo(i,1,lg[n]){
        const int k=1<<i-1; fo(j,1,n-(1<<i)+1)
        mx[i][j]=max(mx[i-1][j], mx[i-1][j+k]),
        mi[i][j]=min(mi[i-1][j], mi[i-1][j+k]);
    }
}

inline int qry(int l, int r){
    const int j=lg[r-l+1];
    return max(mx[j][l], mx[j][r-(1<<j)+1])
          -min(mi[j][l], mi[j][r-(1<<j)+1]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int k; cin>>n>>k;
    
    fo(i,1,n) cin>>a[i];
    build(); ll ans=0;
    
    fo(i,1,n){
        int l=i, r=n, j=i-1;
        while(l<=r){
            int m=l+r>>1;
            if(qry(i, m)<=k) j=m, l=m+1;
            else r=m-1;
        }
        ans+=j-i+1;
    }
    cout<<ans;
}
