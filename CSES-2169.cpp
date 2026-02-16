//link đề: https://lqdoj.edu.vn/problem/cses2169

#include<bits/stdc++.h>
#define ll long long
#define Max(a,b) ({int v=b; a=a>v? a:v;})
#define esc(s) return cout<<(s), 0
#define fo(i,j,n) for(int i=j; i<=n; ++i)
#define fd(i,j,n) for(int i=j; i>=n; --i)
#pragma GCC target("avx2,bmi2")
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;

const int N=2e5+5;
int n, bit[N], l[N], r[N];

void upd(int i){
    for(; i<=n; i+=i&-i) ++bit[i];
}

int get(int i, int s=0){
    for(; i; i-=i&-i) s+=bit[i];
    return s;
}

inline bool cmp(int a, int b){
    if(l[a]==l[b]) return r[a]>r[b];
    return l[a]<l[b];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin>>n; int a[n+1], id[n+1];
    int kq1[n+1], kq2[n+1];
    
    fo(i,1,n) cin>>l[i]>>r[i],
        id[i]=i, a[i]=r[i];
    
    // nén tọa độ r
    sort(a+1, a+n+1);
    int m=unique(a+1, a+n+1)-a-1;
    sort(id+1, id+n+1, cmp);
    
    // đếm chứa bao nhiêu
    fd(i,n,1){
        int p=lower_bound(a+1, a+m+1, r[id[i]])-a;
        kq1[id[i]]=get(p); upd(p);
    }
    // đếm bao nhiêu chứa nó
    fill(bit+1, bit+n+1, 0);

    fo(i,1,n){
        int p=lower_bound(a+1, a+m+1, r[id[i]])-a;
        kq2[id[i]]=get(m)-get(p-1); upd(p);
    }
    // in kq
    fo(i,1,n) cout<<kq1[i]<<' ';
    cout<<'\n';
    fo(i,1,n) cout<<kq2[i]<<' ';
}
