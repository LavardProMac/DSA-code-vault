#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=2001;
int a[N], dp[N], t[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m=1; cin>>n;
    vector<int> v;
    
    fo(i,1,n){
        cin>>a[i]; dp[i]=1;
        
        fo(j,1,i-1) if(a[j]<a[i])
            if(dp[j]>=dp[i])
                dp[i]=dp[j]+1, t[i]=j;
        
        if(dp[i]>dp[m]) m=i;
        
    }
    for(int i=m; i; i=t[i])
        v.push_back(a[i]);
    
    reverse(v.begin(), v.end());
    for(int i:v) cout<<i<<' ';
}
