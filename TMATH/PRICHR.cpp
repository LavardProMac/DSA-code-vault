#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
bitset<123> a; bool v[100005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("PRICHR.INP", "r", stdin);
    freopen("PRICHR.OUT", "w", stdout);
    int t, n, k; cin>>t;

    while(t--){
        string s, t; cin>>n>>s>>k;
        a.reset(); char c; int cnt=0;

        fo(i,1,k) cin>>c, a[c]=1;

        while(++cnt){
            fill(v, v+n, 0); t.clear();

            fo(i,0,n-2)
                if(a[s[i+1]]) v[i]=1;

            fo(i,0,n-1) if(!v[i])
                t.push_back(s[i]);

            if(s==t) break;
            s=t; n=t.size();
        }
        cout<<cnt-1<<'\n';
    }
}
