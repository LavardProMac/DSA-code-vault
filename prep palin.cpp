// palindrome preprocess O(N^2)

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<n; ++i)
using namespace std;
string s; bool p[2001][2001];

void prep(){
    int n=s.size();
    fo(i,0,n) p[i][i]=1;
    
    fo(i,0,n-1) if(s[i]==s[i+1])
        p[i][i+1]=1;
    
    for(int l=n-1; l>=0; --l) fo(r,l+2,n)
        if(s[l]==s[r] && p[l+1][r-1])
            p[l][r]=1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>s; prep();
}
