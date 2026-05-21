// Đề: tính số lượng số có các chữ số phân biệt trong đoạn [l, r]

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

ll a[8877691]; bitset<10> v;
int p[10]={0,9,90,738,5274,32490,168570,712890,2345850,5611770}, c[10];

void gen(ll x, int l){
    a[++c[l]+p[l]]=x; x*=10;

    fo(i,0,9) if(!v[i])
        v[i]=1, gen(x+i, l+1), v[i]=0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
  freopen("HAPDAN.INP", "r", stdin);
  freopen("HAPDAN.OUT", "w", stdout);
  
	int t; ll l, r; cin>>t;
  fo(i,1,9) v[i]=1, gen(i, 0), v[i]=0;

	while(t--) cin>>l>>r,
	    cout<<upper_bound(a+1, a+8877691, r)
	         -lower_bound(a+1, a+8877691, l)<<'\n';
}
