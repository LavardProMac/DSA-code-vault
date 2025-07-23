#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#pragma GCC target("avx2,bmi2")
#pragma GCC optimize("O3,unroll-loops")
#define fo(i,j,n) for(int i=j; i<n; ++i)
using namespace std;

int main(){
		ios::sync_with_stdio(0); cin.tie(0);
		int t, m, n; cin>>t;
		while(t--){ cin>>m>>n;
			vector<vi> p(m, vi(n));
			fo(i,0,m) fo(j,0,n) cin>>p[i][j];
			int l=1, r=1e9, ans=0;
			while(l<=r){	
				int mid=(l+r)/2; vector<vi> c(n);
				fo(i,0,m) fo(j,0,n) if(p[i][j]>=mid)
				c[j].push_back(i); bool ok=1, kt=0;
				fo(j,0,n) if(c[j].empty()) ok=0;
				if(!ok){ r=mid-1; continue;}
				unordered_map<int, int> mp;
				fo(j,0,n) for(int i:c[j]) ++mp[i];
				for(auto [f,s]:mp) if(s>=2){
					kt=1; break;
				}if(kt) ans=mid, l=mid+1;
				else r=mid-1;
			}cout<<ans<<'\n';
		}
}
