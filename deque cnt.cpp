// Dem so doan con co max-min <= k

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=5e6+5;
int a[N], mi[N], mx[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("SDIFF.INP", "r", stdin);
    freopen("SDIFF.OUT", "w", stdout);

    int n, q, m, k, j=1, l1, l2, r1, r2;
    ll p, ans=l1=l2=0; r1=r2=-1;
    cin>>n>>p>>q>>m>>k;

    fo(i,1,n){
        int v=a[i]=(p*i+q)%m;
        while(l1<=r1 && a[mx[r1]]<=v) --r1;
        while(l2<=r2 && a[mi[r2]]>=v) --r2;
        mx[++r1]=mi[++r2]=i;

        while(a[mx[l1]]-a[mi[l2]]>k){
            if(mx[l1]<++j) ++l1;
            if(mi[l2]<j) ++l2;
        }
        ans+=i-j+1;
    }
    cout<<ans;
}
