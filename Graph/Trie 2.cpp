// Source: codeforces.com/gym/467680/problem/B

#include<iostream>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
int tr[3200005][2], sz=1;

void add(int x){
    int p=0;
    for(int i=30; i>=0; --i){
        int b=x>>i&1;
        if(!tr[p][b]) tr[p][b]=sz++;
        p=tr[p][b];
    }
}

int get(int x){
    int p=0, res=0;
    for(int i=30; i>=0; --i){
        int b=x>>i&1;
        if(tr[p][b^1])
            res|=1<<i, p=tr[p][b^1];
        else p=tr[p][b];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x; cin>>n;
    int px=0, ans=0; add(0);

    fo(i,1,n) cin>>x, px^=x,
        ans=max(ans, get(px)),
        add(px);
    cout<<ans;
}
