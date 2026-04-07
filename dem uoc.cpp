// O(sqrt N)
inline int cnt_div(ll n){
    const int s=sqrt(n), k=(n&1)+1;
    int cnt=0;
    
    for(int i=1; i<=s; i+=k)
        if(n%i==0) cnt+=2;
    
    if(1ll*s*s==n) --cnt;
    return cnt;
}
// O(sqrt N/log log N)
inline int cnt_div(ll n){
    int res=1, cnt;
    while(!(n&1)) n>>=1, ++res;
    
    for(int i=3; i*i<=n; i+=2) if(n%i==0){
        cnt=1;
        while(n%i==0) n/=i, ++cnt;
        res*=cnt;
    }
    return n>1? res<<1:res;
}
// O(sqrt N/log N)
inline int cnt_div(int n){
    int ans=1;
    
    for(int i:v){
        if(i*i>n) break;
        if(n%i) continue;
        
        int cnt=1;
        while(n%i==0) n/=i, ++cnt;
        ans*=cnt;
    }
    return n>1? res<<1:res;
}
