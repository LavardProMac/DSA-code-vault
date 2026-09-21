// Source: chuyentinpbc.ucode.vn/problems/bfschess-219629

#include<bits/stdc++.h>
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
int d[1<<16]; queue<int> q;

inline void Try(int s, int p, int np){
    if(s>>np&1) return;
    int ns=s^(1<<p)^(1<<np);
    if(!d[ns]) d[ns]=d[s]+1, q.push(ns);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t=0; char c;
    fo(i,0,15) cin>>c, c==49? t|=1<<i:0;
    q.push(t); t=0;
    fo(i,0,15) cin>>c, c==49? t|=1<<i:0;

    while(!q.empty()){
        int s=q.front(); q.pop();
        if(s==t) return cout<<d[s], 0;
        
        fo(p,0,15) if(s>>p&1){
            if(p>3) Try(s, p, p-4);
            if(p<12) Try(s, p, p+4);
            if(p%4) Try(s, p, p-1);
            if(p%4<3) Try(s, p, p+1);
        }
    }
}
