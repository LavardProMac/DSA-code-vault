// Palindrome preprocessing O(N^2+Q)

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
string s; bool p[10001][10001];

void prep(){
    int n=s.size(); s=' '+s;
    
    fo(i,1,n){
        p[i][i]=1;
        if(s[i]==s[i-1]) p[i-1][i]=1;
    }
    for(int l=n-2; l; --l) fo(r,l+2,n)
        if(s[l]==s[r] && p[l+1][r-1]) p[l][r]=1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>s; prep();
    int q, l, r; cin>>q;
    
    while(q--) cin>>l>>r,
        cout<<(p[l][r]? "YES\n":"NO\n");
}
