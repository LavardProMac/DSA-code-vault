// Đề: tính tổng max-min của mọi đoạn con
// Source: oj.clue.edu.vn/problem/qt_hsg9_26_d

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e5+1;
ll a[N], l[N], r[N], L[N], R[N];
// l: min pre; r: min suf; L: max pre; R: max suf

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    stack<int> s, t; ll ans=0;
    
    fo(i,1,n){
        cin>>a[i];
        while(!s.empty() && a[s.top()]>=a[i])
            s.pop();
        l[i]=s.empty()? i:i-s.top();
        s.push(i);
        
        while(!t.empty() && a[t.top()]<=a[i])
            t.pop();
        L[i]=t.empty()? i:i-t.top();
        t.push(i);
    }
    stack<int>().swap(s);
    stack<int>().swap(t);
    
    for(int i=n; i; --i){
        while(!s.empty() && a[s.top()]>a[i])
            s.pop();
        r[i]=(s.empty()? n+1:s.top())-i;
        s.push(i);
        
        while(!t.empty() && a[t.top()]<a[i])
            t.pop();
        R[i]=(t.empty()? n+1:t.top())-i;
        t.push(i);
    }
    fo(i,1,n)
        ans+=a[i]*(L[i]*R[i]-l[i]*r[i]);
    cout<<ans;
}
