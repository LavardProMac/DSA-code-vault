inline void tsnt(ll n, int cnt=0){
    if(n%2==0){
        while(!(n&1)) n>>=1, ++cnt;
        cout<<"2 "<<cnt<<'\n';
    }for(int i=3; i*i<=n; i+=2){
        if(n%i) continue; cnt=0;
        while(n%i==0) n/=i, ++cnt;
        cout<<i<<' '<<cnt<<'\n';
    }if(n>1) cout<<n<<" 1\n";
}
