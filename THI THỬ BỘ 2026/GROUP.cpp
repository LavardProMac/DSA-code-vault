#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=2e5+5;
int f[N]; ll p[N], g[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; ll s; cin>>n>>s;
    
    int j=-1, bc=-1; ll bv=0;
    fo(i,1,n) cin>>p[i], p[i]+=p[i-1];

    fo(i,1,n){
        while(j+1<i && p[j+1]<=p[i]-s)
            if(f[++j]>bc || f[j]==bc && g[j]-j<bv)
                bc=f[j], bv=g[j]-j;
        
        int c=-1; ll v=4e18;
        if(bc!=-1) c=bc+1, v=bv+i;

        if(c>f[i-1] || c==f[i-1] && v<g[i-1])
            f[i]=c, g[i]=v;
        else f[i]=f[i-1], g[i]=g[i-1];
    }
    cout<<f[n]<<' '<<g[n];
}
