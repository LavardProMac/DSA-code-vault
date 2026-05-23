// Đề: đếm số phần tử phân biệt trong a[l, r]
// Source : oj.vnoi.info/problem/dquery

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
int n, bit[1000001], p[1000001];

void upd(int i, int v){
    if(!i) return;
    for(; i<=n; i+=i&-i) bit[i]+=v;
}

int get(int i, int s=0){
    for(; i; i-=i&-i) s+=bit[i];
    return s;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n; int x, L[n+1];
    fo(i,1,n) cin>>x, L[i]=p[x], p[x]=i;
    
    int q, l, r, k=1; cin>>q;
    array<int, 3> Q[q+1]; int ans[q+1];
    
    fo(i,1,q) cin>>Q[i][1]>>Q[i][0], Q[i][2]=i;
    sort(Q+1, Q+q+1);
    
    fo(i,1,q){
        int r=Q[i][0], l=Q[i][1], id=Q[i][2];
        while(r>=k) upd(k, 1), upd(L[k++], -1);
        ans[id]=get(r)-get(l-1);
    }
    fo(i,1,q) cout<<ans[i]<<'\n';
}
