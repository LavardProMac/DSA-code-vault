const int N=1e6;

//sang uoc O(N log N)
int a[N+1];

void sangUoc(){
    fo(i,1,N)
        for(int j=i; j<=N; j+=i) ++a[j];
}

//sang TSNT nho nhat O(N log log N)
int a[N+1];

void sangSPF(){
    fo(i,2,N) if(!a[i]){
        a[i]=i;
        for(ll j=(ll)i*i; j<=N; j+=i)
            if(!a[j]) a[j]=i;
    }
}

//sang TSNT nho nhat tuyen tinh O(N)
int a[N+1], p[N+1];

void sangSPF_linear(){
    int pc=0; a[1]=1;
    fo(i,2,N){
        if(!a[i]) a[i]=i, p[pc++]=i;
        for(int j=0; j<pc && p[j]<=a[i] && i*p[j]<=N; ++j)
            a[i*p[j]]=p[j];
    }
}

//dem uoc bang sangSPF O(log N)
int cntDiv(int n){
    int res=1;
    while(n>1){
        int p=a[n], cnt=1;
        while(a[n]==p)
            n/=p, ++cnt;
        res*=cnt;
    }
    return res;
}
