#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e6;
int a[N+1]; ll p[N+1];

void prep(){
    fo(i,1,N) for(int j=i; j<=N; j+=i)
        ++a[j];
    fo(i,1,N) p[i]=p[i-1]+a[i];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n; cin>>t; prep();
    while(t--) cin>>n, cout<<p[n]<<'\n';
}
