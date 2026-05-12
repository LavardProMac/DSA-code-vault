bool isP(const ll& n){
    if(n<2) return 0; if(n<4) return 1;
    if(!(n&1 && n%3)) return false;
    
    for(int i=5, s=sqrt(n); i<=s; i+=6)
        if(!(n%i && n%(i+2))) return 0;
    
    return true;
}
