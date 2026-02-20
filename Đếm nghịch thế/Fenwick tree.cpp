// Sol 2: Fenwick tree O(n log N)
// Tối ưu khi ai ≤ 1e6, với 1 ≤ i ≤ n

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
#define fd(i,j,n) for(int i=j; i>=n; --i)
using namespace std;
const int N=1e6; int bit[N+1];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; ll cnt=0; cin>>n; int a[n+1];
    fo(i,1,n) cin>>a[i];
    
    fd(i,n,1){
        int s=0, k=a[i];
        for(int j=k-1; j; j-=j&-j) s+=bit[j];
        cnt+=s;
        for(int j=k; j<=N; j+=j&-j) ++bit[j];
    }
    cout<<cnt;
}
