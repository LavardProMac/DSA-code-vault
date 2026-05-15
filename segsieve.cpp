void segmented_sieve(int l, int r){
    bool p[r-l+1]={};
    
    for(ll i=2; i*i<=r; ++i)
        for(ll j=max(i*i, (l+i-1)/i*i); j<=r; j+=i)
            p[j-l]=1;

    //fo(i,0,l-r) if(!p[i]) cout<<i+l<<' ';
}
