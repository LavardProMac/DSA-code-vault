// Đề: đếm số đoạn con có max - min <= k
// Source: creativecode.vn/problem/subdiff

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    
    int a[n+1], j=1; ll ans=0;
    deque<int> mx, mi;
    
    fo(i,1,n){
        cin>>a[i];
        
        while(!mx.empty() && a[mx.back()]<=a[i])
            mx.pop_back();
        mx.push_back(i);
        
        while(!mi.empty() && a[mi.back()]>=a[i])
            mi.pop_back();
        mi.push_back(i);
        
        while(a[mx.front()]-a[mi.front()]>k){
            if(mx.front()==j) mx.pop_front();
            if(mi.front()==j) mi.pop_front();
            ++j;
        }
        ans+=i-j+1;
    }
    cout<<ans;
}
