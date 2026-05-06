// Brute force O(N*Q)

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
string s;

bool palin(int l, int r){
    while(l<r){
        if(s[l]!=s[r]) return 0;
        ++l; --r;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int q, l, r; cin>>s>>q;
    int n=s.size(); s=' '+s;

    while(q--) cin>>l>>r, 
        cout<<(palin(l, r)? "YES\n":"NO\n");
}
