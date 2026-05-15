#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

bitset<10000001> np;
vector<int> pr={2};

void sieve(const int& n){
    const int s=sqrt(n);
    
    for(int i=3; i<=s; i+=2) if(!np[i]){
        pr.push_back(i);
        for(int j=i*i; j<=n; j+=i<<1) np[j]=1;
    }
    for(int i=s+(s&1)+1; i<=n; i+=2)
        if(!np[i]) pr.push_back(i);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll l, r; cin>>l>>r;
    sieve(sqrt(r));
    
    int n=r-l+1; ll a[n];
    fo(i,0,n-1) a[i]=l+i;

    vector<pair<ll, int>> f[n];

    for(const ll& p:pr){
        ll s=max(p*p, (l+p-1)/p*p);

        for(ll x=s; x<=r; x+=p){
            int i=x-l, c=0;

            while(a[i]%p==0) a[i]/=p, ++c;
            f[i].emplace_back(p, c);
        }
    }
    fo(i,0,n-1) if(a[i]>1)
        f[i].emplace_back(a[i], 1);

    fo(i,0,n-1){
        cout<<l+i<<" = ";
        auto [p,e]=f[i][0];
        
        cout<<p;
        if(e>1) cout<<'^'<<e;
        int q=f[i].size()-1;
        
        fo(j,1,q){
            auto [p,e]=f[i][j];
            cout<<" * "<<p;
            if(e>1) cout<<'^'<<e;
        }
        cout<<'\n';
    }
}
