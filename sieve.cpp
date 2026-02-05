//odd sieve O(N/2 log log N)
const int N=1e6;
bitset<N+1> p;

void sieve(){
    for(int i=3; i<=1000; i+=2) if(!p[i])
        for(int j=i*i, k=i<<1; j<=N; j+=k) p[j]=1;
}

//odd sieve + vector
const int N=1e6;
bitset<N+1> p; vector<int> v={2};

void sieve(){
    for(int i=3; i<=1000; i+=2) if(!p[i]){
        v.pb(i);
        for(int j=i*i, k=i<<1; j<=N; j+=k) p[j]=1;
    }
    for(int i=1001; i<=N; i+=2) if(!p[i]) v.pb(i);
}

//linear sieve O(N)
const int N=1e6;
int lp[N+1], pr[N+1];

void sieve(){
    fo(i,2,N){
        if(!lp[i]) lp[i]=i, pr[++pc]=i;
        for(int j=1; j<=pc && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i*pr[j]]=pr[j];
    }
