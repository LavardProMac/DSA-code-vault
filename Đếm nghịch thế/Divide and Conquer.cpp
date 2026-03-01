// Sol 1: Chia để trị O(N log N)
// Tối ưu khi ai ≤ 1e9, với 1 ≤ i ≤ n

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e6+1;
int a[N], kq[N];

// đếm nghịch thế = merge sort
ll cnt(int l, int m, int r){
    int i=l, j=m+1, k=l; ll d=0; 
    
    while(i<=m && j<=r)
        if(a[i]<=a[j]) kq[k++]=a[i++];
        else kq[k++]=a[j++], d+=m-i+1;
    
    while(i<=m) kq[k++]=a[i++];
    while(j<=r) kq[k++]=a[j++];
    
    fo(i,l,r) a[i]=kq[i];
    return d;
}

// đệ quy đếm toàn bộ
ll dq(int l, int r){
    if(l>=r) return 0; int m=l+r>>1;
    return dq(l,m)+dq(m+1,r)+cnt(l,m,r);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    fo(i,0,n) cin>>a[i];
    
    cout<<dq(0, n-1);
}
