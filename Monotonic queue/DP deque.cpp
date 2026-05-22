// Đề: tìm max tổng giá trị khi chia mảng thành k đoạn con
// Giá trị của 1 đoạn con = abs tổng đoạn đó
// Điều kiện: các đoạn con có số phần tử <= m
// Source: oj.clue.edu.vn/problem/tn_hsg10_26_d

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
ll p[3001], dp[3001][3001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k, m; cin>>n>>k>>m;
    memset(dp, -0x3f, sizeof dp);

    fo(i,1,n) cin>>p[i], p[i]+=p[i-1];
    fo(i,0,m) dp[i][1]=abs(p[i]);
    
    fo(j,2,k){
        deque<int> d1, d2;
        fo(i,1,n){
            const int t=i-1;
            ll t1=dp[t][j-1]+p[t], t2=dp[t][j-1]-p[t];
            
            while(!d1.empty() && dp[d1.back()][j-1]+p[d1.back()]<=t1)
                d1.pop_back();
            d1.push_back(t);
            if(d1.front()<=t-m) d1.pop_front();
            
            while(!d2.empty() && dp[d2.back()][j-1]-p[d2.back()]<=t2)
                d2.pop_back();
            d2.push_back(t);
            if(d2.front()<=t-m) d2.pop_front();
            
            dp[i][j]=max(dp[d1.front()][j-1]+p[d1.front()]-p[i],
                         dp[d2.front()][j-1]+p[i]-p[d2.front()]);
        }
    }
    cout<<dp[n][k];
}
