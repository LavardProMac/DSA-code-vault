// Source: hnoj.edu.vn/problem/word

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=105, M=30005;

int tr[M][26], val[M], cnt=1;
int cl[N][N], dp[N][N], f[N][M];
vector<int> ac[N];

void add(string &s, int w){
    int u=0;
    for(char c:s){
        int x=c-'a';
        if(!tr[u][x]) tr[u][x]=cnt++;
        u=tr[u][x];
    }
    val[u]=max(val[u], w);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s, w; cin>>s;
    int n=s.size(), m, p; cin>>m;
    fo(i,1,m) cin>>w>>p, add(w, p);

    memset(cl, -1, sizeof cl);
    memset(f, -1, sizeof f);
    
    for(int l=n; l; --l){
        f[l-1][0]=0;
        ac[l-1].push_back(0);

        fo(i,l,n){
            int x=s[i-1]-'a';
            for(int u:ac[i-1]){
                int v=tr[u][x];
                if(v){
                    if(f[i][v]==-1) ac[i].push_back(v);
                    f[i][v]=max(f[i][v], f[i-1][u]);
                }
            }
            fo(k,l,i) if(cl[k][i]!=-1)
                for(int u:ac[k-1]){
                    if(f[i][u]==-1) ac[i].push_back(u);
                    f[i][u]=max(f[i][u], f[k-1][u]+cl[k][i]);
                }
            for(int u:ac[i]) if(val[u])
                cl[l][i]=max(cl[l][i], f[i][u]+val[u]);
            fo(k,l,i-1)
                if(cl[l][k]!=-1 && cl[k+1][i]!=-1)
                    cl[l][i]=max(cl[l][i], cl[l][k]+cl[k+1][i]);
        }
        fo(i,l-1,n){
            for(int u:ac[i]) f[i][u]=-1;
            ac[i].clear();
        }
    }
    fo(len,1,n) fo(l,1,n-len+1){
        int r=l+len-1;
        if(cl[l][r]!=-1) dp[l][r]=cl[l][r];
        if(l<r)
            dp[l][r]=max(dp[l][r], dp[l+1][r]),
            dp[l][r]=max(dp[l][r], dp[l][r-1]);
        fo(k,l,r)
            dp[l][r]=max(dp[l][r], dp[l][k]+dp[k+1][r]);
    }
    cout<<dp[1][n];
}
