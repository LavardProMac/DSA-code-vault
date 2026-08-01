// Source: www.spoj.com/problems/TRYCOMP

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<n; ++i)
using namespace std;
const int N=5e5+5;

int tr[N*10][26], id[N*10];
string w[N]; int cnt[N], sz;

inline bool cmp(int a, int b){
    return !b || cnt[a]>cnt[b] ||
    cnt[a]==cnt[b] && w[a]<w[b];
}

void add(const string &s, int k){
    int u=0;
    if(cmp(k, id[u])) id[u]=k;

    for(char c:s){
        int x=c-'a';
        if(!tr[u][x]) tr[u][x]=++sz;
        
        u=tr[u][x];
        if(cmp(k, id[u])) id[u]=k;
    }
}

int get(const string& s){
    int u=0;
    for(char c:s){
        int x=c-'a';
        if(!tr[u][x]) return -1;
        u=tr[u][x];
    }
    return id[u];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m=0; cin>>n; string s;

    unordered_map<string, int> mp;
    fo(i,0,n) cin>>s, ++mp[s];

    for(const auto &[f, s]:mp)
        w[++m]=f, cnt[m]=s;

    fo(i,1,m+1) add(w[i], i);
    int q; cin>>q;

    while(q--){
        cin>>s; int k=get(s);
        if(k==-1) cout<<"-1\n";
        else cout<<w[k]<<' '<<cnt[k]<<'\n';
    }
}
