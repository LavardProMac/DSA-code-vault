#include <bits/stdc++.h>
#define ll long long
#define fo(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

const int N=4005;
const ll INF=4e18;

int n,k;
ll dp[2][N];

inline ll cost(int l,int r){
    // return cost(l,r);
}

void cal(int id,int l,int r,int optl,int optr){
    if(l>r) return;

    int mid=(l+r)>>1;
    pair<ll,int> res={INF,-1};

    fo(i,optl,min(mid,optr)){
        ll cur=dp[id^1][i-1]+cost(i,mid);
        if(cur<res.first) res={cur,i};
    }

    dp[id][mid]=res.first;

    cal(id,l,mid-1,optl,res.second);
    cal(id,mid+1,r,res.second,optr);
}

int main(){
    cin>>n>>k;

    fo(i,1,n) dp[0][i]=cost(1,i);

    fo(i,1,k-1)
        cal(i&1,1,n,1,n);

    cout<<dp[(k-1)&1][n];
}
