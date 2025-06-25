inline void segSieve(const int& l, const int& r){
    vector<bool> p(r-l+1, true); if(l==1) p[0]=false;
    for(int i=2; i*i<=r; ++i)
        for(int j=max(i*i, (l+i-1)/i*i); j<=r; j+=i) p[j-l]=false;
    for(int i=0, k=r-l; i<=k; ++i) if(p[i]) cout<<i+l<<' ';
}
