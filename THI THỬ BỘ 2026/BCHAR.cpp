#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
int a[26];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    string s; ll ans=0; cin>>s;
    
    for(char c:s){
        c-='a';
        int l=max(0, c-k);
        int r=min(25, c+k);
        
        fo(i,l,r) ans+=a[i];
        ++a[c];
    }
    cout<<ans;
}
