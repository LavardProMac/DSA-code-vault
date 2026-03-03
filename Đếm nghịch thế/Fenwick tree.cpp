// Sol 2: Fenwick tree O(n log N)
// Tối ưu khi ai ≤ 1e6, với 1 ≤ i ≤ n

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e6; int n, bit[N+1];

void upd(int i){
    for(; i<=N; i+=i&-i) ++bit[i];
}

int sum(int i, int s=0){
    for(; i; i-=i&-i) s+=bit[i];
    return s;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin>>n; int a[n+1]; ll cnt=0;
    fo(i,1,n) cin>>a[i];
    
    for(int i=n; i; --i)
        cnt+=sum(a[i]-1), upd(a[i]);     
    // tính tổng dãy bit[1, a[i]) và tăng bit[a[i]] lên 1 đơn vị
    // vì duyệt ngược mảng a nên trở thành đếm nghịch thế
    
    cout<<cnt;
}
