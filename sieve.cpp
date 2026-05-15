//sàng Eratosthenes O(N log log N)
const int N=1e6; bitset<N+1> p;

void sieve(){
    p.set(); p[0]=p[1]=0;
    fo(i,2,1000) if(p[i])
        for(int j=i*i; j<=N; j+=i) p[j]=0;
}

//odd sieve O(N/2 log log N)
const int N=1e6; bitset<N+1> p;

void odd_sieve(){
    p[0]=p[1]=1;
    for(int i=3; i<=1000; i+=2) if(!p[i])
        for(int j=i*i, k=i<<1; j<=N; j+=k) p[j]=1;
}

//odd sieve + vector
const int N=1e6;
bitset<N+1> p; vector<int> v={2};

void odd_sieve(){
    for(int i=3; i<=1000; i+=2) if(!p[i]){
        v.pb(i);
        for(int j=i*i, k=i<<1; j<=N; j+=k) p[j]=1;
    }
    for(int i=1001; i<=N; i+=2) if(!p[i]) v.pb(i);
}

//linear sieve O(N)
const int N=1e6;

int a[N+1], v[N+1], pc;
bitset<N+1> p;

void linear_sieve(){
    fo(i,2,N){
        if(!a[i]) a[i]=i, v[++pc]=i, p[i]=1;
        for(int j=1; j<=pc && v[j]<=a[i] && i*v[j]<=N; ++j)
            a[i*v[j]]=v[j];
    }
}

//sàng phi Euler O(N log log N)
const int N=1e6; int f[N+1];

void phi_sieve(){
    fo(i,1,N) f[i]=i;
    fo(i,2,N) if(f[i]==i)
        for(int j=i; j<=N; j+=i) f[j]-=f[j]/i;
}

//sàng phi Euler tuyến tính O(N)
const int N=1e6;

int f[N+1], pr[N+1], pc;
bitset<N+1> v;

void linear_phi_sieve(){
    f[1]=1;
    fo(i,2,N){
        if(!v[i]) pr[++pc]=i, f[i]=i-1;
        fo(j,1,pc){
            ll x=1LL*i*pr[j];
            if(x>N) break;
            v[x]=1;
            if(i%pr[j]==0){
                f[x]=f[i]*pr[j];
                break;
            }
            else f[x]=f[i]*(pr[j]-1);
        }
    }
}
