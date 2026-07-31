// Source: codeforces.com/gym/467680/problem/A

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<n; ++i)
using namespace std;
const int N=10005;

int d[N*50][26], cnt;
bitset<N*50> e;

void add(const string& s){
    int u=0, n=s.size();
    fo(i,0,n){
        int k=s[i]-'a';
        if(!d[u][k]) d[u][k]=++cnt;
        u=d[u][k];
    }
    e[u]=1;
}

bool qry(const string& s){
    int u=0, n=s.size();
    fo(i,0,n){
        int k=s[i]-'a';
        if(!d[u][k]) return 0;
        u=d[u][k];
    }
    return e[u];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n; string s;
    fo(i,0,n) cin>>s, add(s);
    cin>>n;
    while(cin>>s) cout<<qry(s)<<'\n';
}
