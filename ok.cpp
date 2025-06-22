#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
  	long long n; cin >> n;
  	int s=sqrt(n); vector<int> v;
  	for(int i=1; i<=s; ++i)
		if(n%i==0) v.push_back(i),
			cout << n/i << ' ';
	if(1ll*s*s==n) v.pop_back();
	for(auto it=v.rbegin(); it!=v.rend(); ++it)
		cout << *it << ' ';
}
