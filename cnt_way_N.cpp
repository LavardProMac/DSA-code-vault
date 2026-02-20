// Đếm số cách tạo dãy có độ dài N sao cho:
// a[1]*a[2]*...*a[N] == M
// Đpt: O(N + sqrt M)

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fo(i,j,n) for(int i=j; i<=n; ++i)
#define fd(i,j,n) for(int i=j; i>=n; --i)
using namespace std;

const int N=2e5+1, M=1e9+7;
ll f[N], a[N]; vector<int> v;

inline ll mu(ll a, ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%M;
        a=a*a%M, b>>=1;
    }
    return res;
}

void tienxuly(){
    f[0]=1;
    fo(i,1,N) f[i]=f[i-1]*i%M;

    a[N-1]=mu(f[N-1], M-2);
    fd(i,N-1,1) a[i-1]=a[i]*i%M;
}

inline ll C(int n, int k){
    if(k<0 || k>n) return 0;
    return f[n]*a[k]%M*a[n-k]%M;
}

void tsnt(int n){
    int cnt=0;
    if(!(n&1)){
        while(!(n&1)) n>>=1, ++cnt;
        v.pb(cnt);
    }
    for(int i=3; i*i<=n; i+=2){
        if(n%i) continue; cnt=0;

        while(n%i==0) n/=i, ++cnt;
        v.pb(cnt);
    }
    if(n>1) v.pb(1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin>>n>>m; --n;
    ll ans=1; tienxuly(); tsnt(m);

    for(int x:v) ans=ans*C(x+n, n)%M;
    cout<<ans;
}
