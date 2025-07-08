//O(sqrt N)
inline int uoc(ll n, int cnt=0){
    int s=sqrt(n), k=(n&1)+1;
    for(int i=1; i<=s; i+=k)
        if(n%i==0) cnt+=2;
    if(1ll*s*s==n) --cnt;
    return cnt;
}
//O(cbrt N)
inline int uoc2(ll n, int res=1){
    int cnt=1;
    while(!(n&1)) n>>=1, ++cnt;
    res *= cnt;
    for(int i=3; i*i<=n; i+=2){
        if(n%i) continue; cnt=1;
        while(n%i==0) n/=i, ++cnt;
        res *= cnt;
    }return n>1? res*2 : res;
}
//O(log N)
using namespace std; const int N=1e6+1;
bitset<N> p; vector<int> v{2};

inline void sieve(){
    for(int i=3; i<N; i+=2) p[i]=1;
    for(int i=3; i<1001; i+=2) if(p[i])
    for(int j=i*i; j<N; j+=i+i) p[j]=0;
    for(int i=3; i<N; i+=2)
        if(p[i]) v.push_back(i);
}
inline int uoc3(ll n, int res=1){
    for(const int& i : v){
        if(i*i>n) break;
        if(n%i) continue;
        int c=1;
        while(n%i==0) n/=i, ++c;
        res *= c;
    }return n>1? res*2 : res;
}
