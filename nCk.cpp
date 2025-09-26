//đếm số cách tạo dãy có độ dài n sao cho a1*a2*...*an = m
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=2e5+1, M=1e9+7;
ll f[N], a[N]; vector<pii> v;

inline ll mu(ll a, ll b, ll r=1){
    while(b){
        if(b&1) r=r*a%M;
        a=a*a%M, b>>=1;
    }return r;
}
inline void tienxuly(){ f[0]=1;
    fo(i,1,N) f[i]=f[i-1]*i%M;
    a[N-1]=mu(f[N-1], M-2);
    for(int i=N-1; i; --i)
        a[i-1]=a[i]*i%M;
}
inline ll C(int n, int k){
    if(k<0 || k>n) return 0;
    return f[n]*a[k]%M*a[n-k]%M;
}
inline void tsnt(int n, int cnt=0){
    if(n%2==0){
        while(!(n&1)) n>>=1, ++cnt;
        v.emplace_back(2,cnt);
    }for(int i=3; i*i<=n; i+=2){
        if(n%i) continue; cnt=0;
        while(n%i==0) n/=i, ++cnt;
        v.emplace_back(i,cnt);
    }if(n>1) v.emplace_back(n,1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m; ll ans=1;
    tienxuly(); tsnt(m);
    for(auto [f, s] : v)
        ans=(ans*C(s+n-1, n-1))%M;
    cout<<ans;
}
