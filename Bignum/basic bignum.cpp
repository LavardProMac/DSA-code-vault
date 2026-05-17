// hàm cộng 2 xâu O(N)
string add(string a, string b){
    if(a.size()<b.size()) swap(a, b);
    
    int n=a.size()-1;
    int m=b.size()-1, c=0;
    
    fo(i,0,n) c+=a[n-i]-48+
        (i<=m? b[m-i]-48:0),
        a[n-i]=c%10+48, c/=10;
    
    return c? '1'+a:a;
}

// hàm trừ 2 xâu O(N) (a ≥ b)
string sub(string a, const string& b){
    int n=a.size()-1, i=0;
    int m=b.size()-1, c=0, t;
    
    fo(i,0,n) t=a[n-i]-48-c-
        (i<=m? b[m-i]-48:0),
        a[n-i]=t+48+10*(c=t<0);

    while(i<n && a[i]==48) ++i;
    return a.substr(i);
}

// hàm cộng xâu thêm 1 đơn vị O(N)
string add1(string s){
    int i=s.size()-1;
    
    while(i>=0 && s[i]==57)
        s[i--]=48;
    
    if(i>=0) ++s[i];
    else s='1'+s;
    
    return s;
}

// hàm trừ xâu đi 1 đơn vị O(N)
string sub1(string s){
    if(s=="0") return "0";
    int i=s.size()-1;
    
    while(s[i]==48) s[i--]=57;
    int p=0; --s[i];
    
    while(p+1<s.size() && s[p]==48) ++p;
    return s.substr(p);
}

// hàm nhân xâu với 1 số tự nhiên O(N)
string mul(string a, const ll& b){
    int n=a.size()-1; ll c=0;
    reverse(a.begin(), a.end());
    
    fo(i,0,n) c+=b*(a[i]-48),
        a[i]=c%10+48, c/=10;
        
    while(c) a+=c%10+48, c/=10;
    reverse(a.begin(), a.end());
    return a;
}

// hàm chia xâu cho 1 số tự nhiên O(N)
string Div(const string& a, const ll& b){
    string s; ll r=0;
    int n=a.size()-1, i=0;
    
    fo(i,0,n) r=r*10+a[i]-48,
        s.push_back(r/b+48), r%=b;
    
    while(i<n && s[i]==48) ++i;
    return s.substr(i);
}

// hàm chia lấy dư xâu cho 1 số tự nhiên O(N)
ll mod(const string& s, const ll& M){
    ll rem=0;
    for(char c:s) rem=(rem*10+c-48)%M;
    return rem;
}

// hàm nhân 2 xâu O(N.M)
string Mul(const string& a, const string& b){
    int n=a.size(), m=b.size();
    int p=n+m, t[p+2]={}; string s;
    
    fo(i,1,n) fo(j,1,m) t[i+j-1]+=
        (a[n-i]-48)*(b[m-j]-48);
        
    fo(i,1,p) t[i+1]+=t[i]/10, t[i]%=10;
    while(p>1 && !t[p]) --p; ++p;
    
    while(--p) s.push_back(t[p]+48);
    return s;
}
