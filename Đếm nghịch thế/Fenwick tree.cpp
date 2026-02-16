// Sol 2: Fenwick tree (BIT) O(n log N)
// Tối ưu khi ai ≤ 1e6

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
#define fd(i,j,n) for(int i=j; i>=n; --i)
using namespace std;
const int N=1e6; int t[N+1];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin>>n; int a[n+1]; ll cnt=0;
    fo(i,1,n) cin>>a[i];
    
    fd(i,n,1){
        int s=0, k=a[i];
        for(int j=k-1; j; j-=j&-j) s+=t[j];
        cnt+=s;
        for(int j=k; j<=N; j+=j&-j) ++t[j];
    }
    cout<<cnt;
}
