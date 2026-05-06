// Name: unweighted interval scheduling
// Source: cses.fi/problemset/task/1629

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<n; ++i)
using namespace std;
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
 
    pair<int, int> a[n];
    for(auto& [f,s]:a) cin>>s>>f; // đổi thứ tự nhập start và end
 
    sort(a, a+n); // sort theo ending time
    int cnt=1, d=a[0].first; // chọn đoạn a[0] và đặt d := end a[0]
 
    fo(i,1,n) if(a[i].second>=d) // nếu a[i] start sau hoặc cùng d thì 
        d=a[i].first, ++cnt;     // d := end a[i] và tính vào cnt
 
    cout<<cnt;
}
