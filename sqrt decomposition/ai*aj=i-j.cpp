// Source: vjudge.net/contest/843978#problem/C

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
int a[200005];

void solve(){
    int n; cin>>n; ll ans=0;
    fo(i,1,n) cin>>a[i];
    int cnt[n+1], s=sqrt(n);
    // đặt s = căn n
    // nếu ai <= s thì giả sử ai={1,2,...,s}
    // với mỗi ai, đếm xem có bao nhiêu aj sao cho j+ai*aj = i
    // ta cố định ai=x, biến đổi:
    // ai*aj = i-j <=> i = j+x*aj
    // với mỗi j, tính giá trị j+x*aj và lưu số lần xuất hiện
    // sau đó với mọi i có ai=x, cộng số j thỏa mãn vào ans

    fo(x,1,s){
        memset(cnt, 0, sizeof cnt);
        fo(j,1,n){
            ll v=j+1ll*x*a[j];
            if(v<=n) ++cnt[v];
        }
        fo(i,1,n) if(a[i]==x)
            ans+=cnt[i];
    }
    // nếu ai > s thì aj sẽ < s vì:
    // ai*aj = i-j<n
    // => aj < n/ai<n/s ~= s
    // vậy aj chỉ có thể nhận các giá trị 1..s
    // cố định i và thử từng giá trị y=aj
    // từ ai*aj = i-j suy ra: j = i-ai*y
    // khi đã biết i, ai và y thì j được xác định duy nhất
    // chỉ cần kiểm tra j có nằm trong [1, n] và a[j] = y

    fo(i,1,n) if(a[i]>s) fo(y,1,s){
        ll j=i-1LL*a[i]*y;
        if(j<1) break;
        if(a[j]==y) ++ans;
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}
