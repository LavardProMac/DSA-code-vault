// Source: www.spoj.com/problems/ADAINDEX

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<n; ++i)
using namespace std;

const int N=1e6+5;
int d[N][26], cnt[N], sz;

void add(const string& s){
    int u=0, n=s.size();
    fo(i,0,n){
        int k=s[i]-'a';
        if(!d[u][k]) d[u][k]=++sz;
        ++cnt[u=d[u][k]];
    }
}

int qry(const string& s){
    int u=0, n=s.size();
    fo(i,0,n){
        int k=s[i]-'a';
        if(!d[u][k]) return 0;
        u=d[u][k];
    }
    return cnt[u];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m; string s;
    
    fo(i,0,n) cin>>s, add(s);
    fo(i,0,m) cin>>s, cout<<qry(s)<<'\n';
}
