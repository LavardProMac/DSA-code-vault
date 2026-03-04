// hàm cộng 2 xâu O(N)
string add(string a, string b){
    int n=a.size()-1;
    int m=b.size()-1, c=0;
    if(n<m) swap(a, b), swap(n, m);
    
    fo(i,0,n) c+=a[n-i]-48+
        (i<=m? b[m-i]-48:0),
        a[n-i]=c%10+48, c/=10;
    
    return c? '1'+a:a;
}

// hàm trừ 2 xâu O(N) (a ≥ b)
string sub(string a, string b){
    int n=a.size()-1, i=0;
    int m=b.size()-1, c=0, t;
    
    fo(i,0,n) t=a[n-i]-48-c-
        (i<=m? b[m-i]-48:0),
        a[n-i]=(c=t<0)? t+58:t+48;

    while(i<n && a[i]==48) ++i;
    return a.substr(i);
}

// hàm nhân xâu với 1 số nguyên O(N)
string mul(string a, ll b){
    int n=a.size()-1; ll c=0;
    reverse(a.begin(), a.end());
    
    fo(i,0,n) c+=b*(a[i]-48),
        a[i]=c%10+48, c/=10;
        
    while(c) a+=c%10+48, c/=10;
    reverse(a.begin(), a.end());
    return a;
}

// hàm chia xâu cho 1 số nguyên O(N)
string Div(string a, ll b){
    string s; ll r=0;
    int n=a.size()-1, i=0;
    
    fo(i,0,n) r=r*10+a[i]-48,
        s.push_back(r/b+48), r%=b;
    
    while(i<n && s[i]==48) ++i;
    return s.substr(i);
}

// hàm nhân 2 xâu O(N·M)
string Mul(string a, string b){
    int n=a.size(), m=b.size();
    int p=n+m, t[p+2]={}; string s;
    
    fo(i,1,n) fo(j,1,m) t[i+j-1]+=
        (a[n-i]-48)*(b[m-j]-48);
        
    fo(i,1,p) t[i+1]+=t[i]/10, t[i]%=10;
    while(p>1 && !t[p]) --p; ++p;
    
    while(--p) s.push_back(t[p]+48);
    return s;
}
