// Sol 1: Chia để trị O(N log N)
// Tối ưu khi ai ≤ 1e9, với 1 ≤ i ≤ n

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e6+1; int a[N], t[N];

// đếm nghịch thế = merge sort
ll MS(int l, int r){
    if(l>=r) return 0;
    
    int m=l+r>>1, i=l, j=m+1, k=l;
    ll cnt=MS(l, m)+MS(m+1, r);
    
    while(i<=m && j<=r)
        if(a[i]<=a[j]) t[k++]=a[i++];
        else t[k++]=a[j++], cnt+=m-i+1;
    
    while(i<=m) t[k++]=a[i++];
    while(j<=r) t[k++]=a[j++];
    
    fo(i,l,r) a[i]=t[i];
    return cnt;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    fo(i,1,n) cin>>a[i];
    cout<<MS(1, n);
}
