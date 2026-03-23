// coordinate compression (nén tọa độ)
#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int a[n+1], b[n+1];

    fo(i,1,n) cin>>a[i], b[i]=a[i];

    sort(b+1, b+n+1);
    int m=unique(b+1, b+n+1)-b-1;

    fo(i,1,n) a[i]=lower_bound(b+1, b+m+1, a[i])-b;
}
