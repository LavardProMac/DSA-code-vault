using namespace std; const int N=1e6+1;
int spf[N], a[N]; //spf : smallest prime factor
//O(N log N)
inline void sanguoc(){
    fo(i,1,N) for(int j=i; j<N; j+=i) ++a[j];
}
//O(N log log N)
void sangSpf(){
    int pc=0; a[1]=1;
    fo(i,2,N){
        if(!a[i]) a[i]=i, p[pc++]=i;
        for(ll j=0; j<pc && p[j]<=a[i] && i*p[j]<=N; ++j)
            a[i*p[j]]=p[j];
    }
}
inline int cntDiv(int x, int res=1){
    while(x>1){
        int p=spf[x], cnt=1;
        while(spf[x]==p)
            x/=p, ++cnt;
        res *= cnt;
    }return res;
}
