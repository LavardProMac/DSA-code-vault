const int N=1e6;
int n, j, a[N+1], c[N+1];

void count_sort(){
    fo(i,1,n) ++c[a[i]];
    fo(i,1,N) while(c[v]--) a[++j]=v;
}
