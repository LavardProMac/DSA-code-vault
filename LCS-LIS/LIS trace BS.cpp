#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=2e5+5;
int a[N], p[N], id[N], t[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m=1; cin>>n; vector<int> v;
    
    fo(i,1,n){
        cin>>a[i];
        int k=lower_bound(p+1, p+m+1, a[i])-p;
        
        p[k]=a[i]; id[k]=i;
        t[i]=id[k-1]; m=max(m, k);
        
    }
    for(int i=id[m]; i; i=t[i])
        v.push_back(a[i]);
    reverse(v.begin(), v.end());
    
    cout<<p[m]<<'\n';
    for(int i:v) cout<<i<<' ';
}
