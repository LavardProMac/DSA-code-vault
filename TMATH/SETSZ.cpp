// Đề: Cho mảng a có n phần tử và q truy vấn.
// Mỗi truy vấn nhập x, gọi S là tập hợp các giá trị {ai+1, ai+2, ..., ai+x} với 1<=i<=n.
// Yêu cầu: Tính số lượng giá trị khác nhau trong tập S.

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("SETSZ.INP", "r", stdin);
  	freopen("SETSZ.OUT", "w", stdout);
    
    int n, q; cin>>n>>q; int a[n+1];
    fo(i,1,n) cin>>a[i];
    
    sort(a+1, a+n+1);
    n=unique(a+1, a+n+1)-a-1;
    
    int d[n]; ll p[n--]; d[0]=p[0]=0;
    fo(i,1,n) d[i]=a[i+1]-a[i];
    
    sort(d+1, d+n+1); p[1]=d[1];
    fo(i,2,n) p[i]=p[i-1]+d[i];
    
    while(q--){
        ll x; cin>>x;
        int id=lower_bound(d+1, d+n+1, x)-d-1;
        cout<<x*(n-id+1)+p[id]<<'\n';
    }
}
