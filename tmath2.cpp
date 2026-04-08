// Source: c.tmathcoding.vn/contest/9c1060426/task/9
// KMP O(N*|S|+|T|)

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
ll sf[25], pf[25], f[25], f2[25];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("C.inp", "r", stdin);
    freopen("C.out", "w", stdout);
    
    string t, s; int n; cin>>t>>n;
    int c=0, m=t.size()-1; ll ans=0;

    fo(i,1,m){
        int j=f[i-1];
        while(j && t[i]!=t[j]) j=f[j-1];
        
        if(t[i]==t[j]) ++j;
        f[i]=j;
    }
    string r=t;
    reverse(r.begin(), r.end());

    fo(i,1,m){
        int j=f2[i-1];
        while(j && r[i]!=r[j]) j=f2[j-1];
        
        if(r[i]==r[j]) ++j;
        f2[i]=j;
    }
    for(i,1,n){
        cin>>s;
        int l=s.size()-1, j=0;

        fo(i,0,l){
            while(j && s[i]!=t[j]) j=f[j-1];
            
            if(s[i]==t[j]) ++j;
            if(j==m) j=f[j-1], ++c;
        }
        ++sf[j]; j=0;
        reverse(s.begin(), s.end());

        fo(i,0,l){
            while(j && s[i]!=r[j]) j=f2[j-1];
            if(s[i]==r[j]) ++j;
        }
        ++pf[j];
    }
    for(int i=m+1; i; --i)
        sf[f[i-1]]+=sf[i],
        pf[f2[i-1]]+=pf[i];
    
    fo(i,1,m) ans+=sf[i]*pf[m-i];
    cout<<ans+2ll*c*n;
}
