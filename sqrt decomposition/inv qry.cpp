// Source: vjudge.net/contest/840105#problem/B

#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(), a.end()
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=250005, BL=500;

int n, a[N], b[N], bit[50005];
vector<int> v[N/BL+5];

void add(int x){
    for(; x<=5e4; x+=x&-x) ++bit[x];
}

int sum(int x, int s=0){
    for(; x; x-=x&-x) s+=bit[x];
    return s;
}

void build(int id){
    v[id].clear();
    int l=id*BL+1, r=min(n, (id+1)*BL);
    
    fo(i,l,r) v[id].push_back(a[i]);
    sort(all(v[id]));
}

int left(int p, int x){
    int id=(p-1)/BL, res=0;
    fo(i,id*BL+1,p-1) if(a[i]>x) ++res;
    
    for(int j=id-1; j>=0; --j)
        res+=v[j].end()-upper_bound(all(v[j]), x);
    return res;
}

int right(int p, int x){
    int id=(p-1)/BL, res=0;
    int r=min(n, (id+1)*BL);
    fo(i,p+1,r) if(a[i]<x) ++res;
    
    fo(j,id+1,(n+BL-1)/BL-1)
        res+=lower_bound(all(v[j]), x)-v[j].begin();
    return res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n; ll ans=0;
    fo(i,1,n) cin>>a[i];
    
    for(int i=n; i; --i)
        ans+=sum(a[i]-1), add(a[i]);

    int nb=(n+BL-1)/BL;
    fo(i,0,nb-1) build(i);
    int m; cin>>m;

    while(m--){
        int x, y; cin>>x>>y;
        ans-=left(x, a[x]);
        ans-=right(x, a[x]);
        
        ans+=left(x, y);
        ans+=right(x, y);
        
        a[x]=y;
        build((x-1)/BL);
        cout<<ans<<'\n';
    }
}
