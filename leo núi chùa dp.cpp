// Tên bài: Chú tiểu Chùa Hương
// Nguồn: codeforces.com/group/py59YCge5m/contest/648321/problem/D

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
#pragma GCC target("avx2,bmi2")
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
int x[501], y[501], t[501];

int m, n;
// m là số bậc lên chùa, n là số bậc lên núi
// giữa chân chùa và chân núi có 1 thung lũng

// cần tính số cách từ chùa xuống thung lũng
// rồi lên núi sau đó đi ngược lại về chùa

ll dp1[501], dp2[501];
// dp1: xuống chùa, dp2: lên núi
// xuống chùa và lên núi đc đi 1, 2, hoặc 3 bậc

ll dp3[501][2], dp4[501];
// dp3: xuống núi, dp4: lên chùa
// xuống núi đc đi 1 hoặc 2 bậc, nhưng đc phép đi 3 bậc đúng 1 lần
// lên chùa đc đi 1 hoặc 2 bậc


void preprocess(){
    dp1[0]=dp1[1]=dp2[0]=dp2[1]=1;
    dp1[2]=dp2[2]=2;
    
    dp3[0][0]=dp3[1][0]=dp4[0]=dp4[1]=1;
    dp3[1][1]=dp3[2][1]=0; dp3[2][0]=2;
    // khởi tạo base-case
    
    fo(i,3,500)
        dp1[i]=dp1[i-1]+dp1[i-2]+dp1[i-3],
        // tính số cách từ chùa xuống thung lũng (1)
    
        dp2[i]=dp2[i-1]+dp2[i-2]+dp2[i-3],
        // tính số cách từ thung lũng lên núi (2)
    
        dp3[i][0]=dp3[i-1][0]+dp3[i-2][0],
        dp3[i][1]=dp3[i-1][1]+dp3[i-2][1]+dp3[i-3][0],
        // tính số cách từ núi xuống thung lũng (3)
    
        dp4[i]=dp4[i-1]+dp4[i-2],
        // tính số cách từ thung lũng lên chùa (4)
}

string mul(string a, string b){
    int n=a.size(), m=b.size(), p=n+m;
    fill(t+1, t+p+1, 0); string s;
    
    fo(i,1,n) x[i]=a[n-i]-48;
    fo(i,1,m) y[i]=b[m-i]-48;
    
    fo(i,1,n) fo(j,1,m) t[i+j-1]+=x[i]*y[j];
    fo(i,1,p) t[i+1]+=t[i]/10, t[i]%=10;

    while(p>1 && !t[p]) --p; ++p;
    while(--p) s.push_back(t[p]+48);
    
    return s;
}

void print(ll a, ll b, ll c, ll d){
    string A=to_string(a);
    string B=to_string(b);
    
    string C=to_string(c);
    string D=to_string(d);
    
    cout<<mul(mul(A, B), mul(C, D))<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    preprocess();
    // tiền xử lý số cách đi-về 2 chuyến
    
    while(cin>>m>>n)
        print(dp1[m], dp2[n], dp3[n][1], dp4[m]);
        // dùng nhân xâu để in kq
}
