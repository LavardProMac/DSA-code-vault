using namespace std; const int N=1e6+1;
int spf[N], a[N]; //spf : smallest prime factor
//O(N log N)
inline void sanguoc(){
    fo(i,1,N) for(int j=i; j<N; j+=i) ++a[j];
}
//O(N log log N)
inline void sangSpf(){ spf[1]=1;
    for(int i=2; i<N; i+=2) spf[i]=2;
    for(int i=3; i<N; i+=2) if(!spf[i]){
        spf[i]=i;
        for(int j=i*i; j<N; j+=i<<1)
            if(!spf[j]) spf[j]=i;
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
