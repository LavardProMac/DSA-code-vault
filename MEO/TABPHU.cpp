// Name:  Tối ưu cuộc đời

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<n; ++i)
using namespace std;

int solve(){
    int n, cnt=0, d=0;
    string s; cin>>n>>s;
    
    fo(i,0,n)
        if(s[i]==49) ++cnt, ++d;
        else --d;
    
    if(!cnt) return -1;
    if(s=="1") return 0;
    if(d>=0) return n;
    
    bool pa=0, sa=0, pb=0, sb=d=0;
    fo(i,0,n){
        d+=s[i]==49? 1:-1;
        if(d>0) pa=1;
        if(d>=0) pb=1;
    }
    bool ok=d=0;
    for(int i=n-1; i>=0; --i){
        d+=s[i]==49? 1:-1;
        if(d>0) sa=1;
        if(d>=0) sb=1;
    }
    fo(i,1,n) if(s[i]==49 && s[i-1]==49){
        ok=1; break;
    }
    if(pa || sa || d==-1) return n+1;
    if(pb || sb || ok) return n+2;
    return n+3;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("TABPHU.INP", "r", stdin);
    freopen("TABPHU.OUT", "w", stdout);
    
    int t; cin>>t;
    while(t--) cout<<solve()<<'\n';
}
