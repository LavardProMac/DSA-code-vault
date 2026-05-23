// Đề: Cho x + y + z = n và 3 mảng a[n], b[n], c[n]
// Chọn x số từ a, y số từ b và z số từ c thỏa mãn:
// - không có 2 số nào trùng chỉ số
// - tổng tất cả các số được chọn là lớn nhất

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

ll dp[105][105][105];
// dp[i][j][k]: tổng lớn nhất khi xét tới vị trí i:
// - đã chọn j số từ b
// - đã chọn k số từ c
// => số a đã chọn là: i−j−k
// ĐPT: O(nyz)

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int x, y, z; cin>>x>>y>>z;
    int n=x+y+z;
    
    int a[n+1], b[n+1], c[n+1];
    fo(i,1,n) cin>>a[i]>>b[i]>>c[i];
    
    memset(dp, -0x3f, sizeof dp);
    dp[0][0][0]=0;

    fo(i,0,n-1) fo(j,0,min(i, y)) fo(k,0,min(i-j, z)){
        ll v=dp[i][j][k];
        if(v<0) continue;
        int t=i-j-k;
        
        if(t<x) // chọn ai
            dp[i+1][j][k]=max(dp[i+1][j][k], v+a[i+1]);
            
        if(j<y) // chọn bi
            dp[i+1][j+1][k]=max(dp[i+1][j+1][k], v+b[i+1]);
            
        if(k<z) // chọn ci
            dp[i+1][j][k+1]=max(dp[i+1][j][k+1], v+c[i+1]);
    }
    cout<<dp[n][y][z];
}
