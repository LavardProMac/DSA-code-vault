#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1001, MOD=1e9+7;
bitset<N> p; vector<int> v={2};

inline void sieve(const int& n){
    for(int i=3; i<=n; i+=2) p[i]=1;
    for(int i=3; i*i<=n; i+=2) if(p[i])
    for(int j=i*i; j<=n; j+=i+i) p[j]=0;
    for(int i=3; i<=n; i+=2)
        if(p[i]) v.push_back(i);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n; sieve(n); ll ans=1;
    for(int i : v){ ll e=0, x=i;
        while(x<=n) e+=n/x, x*=i;
        ans=ans*(e+1)%MOD;
    }cout<<ans;
}
