// Old Driver tree: dùng set để lưu các block cùng kí tự
// mỗi node lưu chỉ số bắt đầu, kết thúc và loại kí tự
// khi cập nhật [l, r], phá các block cũ và tách ra:
// [x, l-1], [l, r], [r+1, y]
// đpt: O(n log n)
// Source: hnoj.edu.vn/problem/t6lrsort

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

struct tp{
    int l, r, v;
    tp(int l, int r=-1, int v=0):
        l(l), r(r), v(v){}
    bool operator<(const tp& x) const{
        return l<x.l;
    }
};
set<tp> s;

auto tach(int p){
    auto it=s.lower_bound(tp(p));
    if(it!=s.end() && it->l==p) return it;
    
    int l=(--it)->l, r=it->r, v=it->v;
    s.erase(it);
    s.insert(tp(l, p-1, v));
    return s.insert(tp(p, r, v)).first;
}

void upd(int l, int r, int t){
    auto ir=tach(r+1), il=tach(l);
    int cnt[26]={};

    for(auto it=il; it!=ir; ++it)
        cnt[it->v]+=it->r-it->l+1;
    s.erase(il, ir); int cur=l;
    
    if(t==1){
        fo(i,0,25) if(cnt[i])
            s.insert(tp(cur,cur+cnt[i]-1,i)),
            cur+=cnt[i];
    }else
        for(int i=25; i>=0; --i) if(cnt[i])
            s.insert(tp(cur,cur+cnt[i]-1,i)),
            cur+=cnt[i];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, st=1; string str;
    int t, l, r; cin>>n>>q>>str;

    fo(i,1,n-1) if(str[i]!=str[i-1])
        s.insert(tp(st,i,str[st-1]-'A')),
        st=i+1;

    s.insert(tp(st,n,str[st-1]-'A'));
    s.insert(tp(n+1, n+1));
    while(q--) cin>>t>>l>>r, upd(l, r, t);
    
    for(auto it:s){
        if(it.l>n) break;
        fo(i,it.l,it.r) putchar(it.v+'A');
    }
}
