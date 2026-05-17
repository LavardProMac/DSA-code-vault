#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=2005;
int a[N][N], mx[N][N], mi[N][N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("SQUARE.INP", "r", stdin);
    freopen("SQUARE.OUT", "w", stdout);
    
    int m, n, k, d; cin>>m>>n>>k>>d;
    int s=k<<1|1, cnt=0;
    fo(i,1,m) fo(j,1,n) cin>>a[i][j];
    
    fo(j,1,m){
        deque<int> d1, d2;
        fo(i,1,n){
            while(!d1.empty() && a[j][d1.back()]<=a[j][i])
                d1.pop_back();
            d1.push_back(i);
            if(d1.front()<=i-s) d1.pop_front();
            
            while(!d2.empty() && a[j][d2.back()]>=a[j][i])
                d2.pop_back();
            d2.push_back(i);
            if(d2.front()<=i-s) d2.pop_front();
            
            if(i>=s)
                mx[j][i]=a[j][d1.front()],
                mi[j][i]=a[j][d2.front()];
        }
    }
    fo(j,s,n){
        deque<int> d1, d2;
        fo(i,1,m){
            while(!d1.empty() && mx[d1.back()][j]<=mx[i][j])
                d1.pop_back();
            d1.push_back(i);
            if(d1.front()<=i-s) d1.pop_front();
            
            while(!d2.empty() && mi[d2.back()][j]>=mi[i][j])
                d2.pop_back();   
            d2.push_back(i);
            if(d2.front()<=i-s) d2.pop_front();
            
            if(i>=s && mx[d1.front()][j]-mi[d2.front()][j]>=d)
                ++cnt;
        }
    }
    cout<<cnt;
}
