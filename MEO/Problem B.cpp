// Name: Tối ưu cuộc đời

#include<bits/stdc++.h>
#define fo(i,j,n) for(int i=j;i<=n;i++)
using namespace std;

const int N=200005, INF=2000000000;
int t,n;
char s[N];
int pr[N],sf[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("TABPHU.inp","r",stdin);
    freopen("TABPHU.out","w",stdout);

    cin>>t;
    while(t--){
        cin>>n;
        int c1=0;
        fo(i,1,n){
            cin>>s[i];
            c1+=s[i]=='1';
        }

        if(!c1){
            cout<<-1<<"\n";
            continue;
        }

        int c0=0;
        pr[0]=sf[n+1]=INF;

        fo(i,1,n){
            if(s[i]=='1') c1++;
            else c0++;
            if(c1){
                int v=pr[i-1]+2;
                if(s[i]=='1') v=i+1;
                if(c1>=c0) v=min(v,2*c0);
                pr[i]=v;
            }else pr[i]=INF;
        }

        c1=0, c0=0;
        for(int i=n;i>=1;i--){
            if(s[i]=='1') c1++;
            else c0++;
            if(c1){
                int v=sf[i+1]+2;
                if(s[i]=='1') v=n-i+2;
                if(c1>=c0) v=min(v,2*c0);
                sf[i]=v;
            }else sf[i]=INF;
        }

        int ans=INF;
        fo(i,1,n){
            if(s[i]!='1') continue;
            int v=pr[i-1]+sf[i+1];
            v=min(v,pr[i]+sf[i]);
            v=min(v,pr[i]+sf[i+1]);
            v=min(v,pr[i-1]+sf[i]);
            ans=min(ans,v);
        }

        cout<<ans<<"\n";
    }
    return 0;
}
