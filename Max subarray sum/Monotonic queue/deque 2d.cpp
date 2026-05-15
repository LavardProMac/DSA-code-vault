// Sliding window O(N*M)

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=2005;
int a[N][N], mx[N][N], mn[N][N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k, d; cin>>n>>m>>k>>d;
    int s=k<<1|1, cnt=0;
    
    deque<int> q1, q2;
    fo(i,1,n) fo(j,1,m) cin>>a[i][j];

    fo(i,1,n){
        q1.clear(); q2.clear();

        fo(j,1,m){
            while(!q1.empty() && a[i][q1.back()]<=a[i][j])
                q1.pop_back();
            q1.push_back(j);

            while(q1.front()<=j-s) q1.pop_front();

            while(!q2.empty() && a[i][q2.back()]>=a[i][j])
                q2.pop_back();
            q2.push_back(j);

            while(q2.front()<=j-s) q2.pop_front();

            if(j>=s)
                mx[i][j]=a[i][q1.front()],
                mn[i][j]=a[i][q2.front()];
        }
    }
    fo(j,s,m){
        q1.clear(); q2.clear();

        fo(i,1,n){
            while(!q1.empty() && mx[q1.back()][j]<=mx[i][j])
                q1.pop_back();
            q1.push_back(i);

            while(q1.front()<=i-s) q1.pop_front();

            while(!q2.empty() && mn[q2.back()][j]>=mn[i][j])
                q2.pop_back();
            q2.push_back(i);

            while(q2.front()<=i-s) q2.pop_front();

            if(i>=s){
                int ma=mx[q1.front()][j];
                int mi=mn[q2.front()][j];
                if(ma-mi>=d) ++cnt;
            }
        }
    }
    cout<<cnt;
}
