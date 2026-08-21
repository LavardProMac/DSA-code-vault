// Source: hnoj.edu.vn/problem/dij

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int n;
ll d[405][405], nw[3][3];
ll out[3][405], in[405][3];
ll st[3][405], sn[405][3];
ll fout[3][405], fin[405][3];

void init(){
    memset(d, 0x3f, sizeof d);
    fo(i,1,n) d[i][i]=0;
}

void floyd(){
    fo(k,1,n) fo(i,1,n) fo(j,1,n)
        d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
}

void input(int e){
    memset(out, 0x3f, sizeof out);
    memset(in, 0x3f, sizeof in);
    memset(nw, 0x3f, sizeof nw);
    nw[0][0]=nw[1][1]=nw[2][2]=0;

    fo(i,1,e){
        int u, v; ll w; cin>>u>>v>>w;
        if(u<=n && v>n)
            in[u][v-n-1]=min(in[u][v-n-1], w);
        else if(u>n && v<=n)
            out[u-n-1][v]=min(out[u-n-1][v], w);
        else if(u>n && v>n)
            nw[u-n-1][v-n-1]=min(nw[u-n-1][v-n-1], w);
    }
}

void old(){
    memcpy(st, out, sizeof st);
    memcpy(sn, in, sizeof sn);

    fo(x,0,2) fo(u,1,n) fo(v,1,n)
        st[x][v]=min(st[x][v], out[x][u]+d[u][v]);
    fo(u,1,n) fo(v,1,n) fo(x,0,2)
        sn[u][x]=min(sn[u][x], d[u][v]+in[v][x]);
}

void New(){
    fo(x,0,2) fo(y,0,2) fo(u,1,n)
        nw[x][y]=min(nw[x][y], st[x][u]+in[u][y]);
    fo(k,0,2) fo(i,0,2) fo(j,0,2)
        nw[i][j]=min(nw[i][j], nw[i][k]+nw[k][j]);
}

void final(){
    fo(x,0,2) fo(v,1,n){
        fout[x][v]=st[x][v];
        fo(y,0,2)
            fout[x][v]=min(fout[x][v], nw[x][y]+st[y][v]);
    }
    fo(u,1,n) fo(x,0,2){
        fin[u][x]=sn[u][x];
        fo(y,0,2)
            fin[u][x]=min(fin[u][x], sn[u][y]+nw[y][x]);
    }
}

ll get(){
    ll ans=0;
    fo(u,1,n) fo(v,1,n) if(u!=v){
        ll x=d[u][v];
        fo(y,0,2) x=min(x, fin[u][y]+fout[y][v]);
        ans+=x;
    }
    fo(x,0,2) fo(v,1,n) ans+=fout[x][v];
    fo(u,1,n) fo(x,0,2) ans+=fin[u][x];
    fo(x,0,2) fo(y,0,2) if(x!=y) ans+=nw[x][y];
    return ans;
}

void solve(int e){
    input(e);
    old(); New(); final();
    cout<<get()<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int m, k; cin>>n>>m>>k;
    int u, v; ll w; init();

    fo(i,1,m) cin>>u>>v>>w,
        d[u][v]=min(d[u][v], w);

    floyd();
    while(k--) cin>>u, solve(u);
}
