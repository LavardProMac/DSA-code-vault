#include<bits/stdc++.h>
#define ll long long
using namespace std; int a[1000005];

inline bool kt(int n){ int d, ans=0;
    while(n) d=n%10, ans+=d*d, n/=10;
    return ans%2==0;
}
inline void tienxuly(){
    for(int i=1; i<1000001; ++i)
        a[i]=a[i-1]+kt(i);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t, l, r; cin>>t; tienxuly(); 
    while(t--) cin>>l>>r,
        cout<<a[r]-a[l-1]<<'\n';
}
