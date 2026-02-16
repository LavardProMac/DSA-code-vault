// Đếm số cặp (i, j) thỏa mãn: 
// aj < ai với 1 ≤ j ≤ n

//Sol 1: Chia để trị O(N log N)
#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e6+1;
int a[N], kq[N];

ll tri(int l, int m, int r){
    int i=l, j=m+1, k=l; ll d=0; 
    
    while(i<=m && j<=r)
        if(a[i]<=a[j]) kq[k++]=a[i++];
        else kq[k++]=a[j++], d+=m-i+1;
    
    while(i<=m) kq[k++]=a[i++];
    while(j<=r) kq[k++]=a[j++];
    
    fo(i,l,r) a[i]=kq[i];
    return d;
}

ll chia(int l, int r){
    if(l>=r) return 0;
    const int m=l+r>>1;
    return chia(l,m)+chia(m+1,r)+tri(l,m,r);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    fo(i,0,n) cin>>a[i];
    cout<<chia(0, n-1);
}
