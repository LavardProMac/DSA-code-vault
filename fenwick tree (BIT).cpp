using namespace std; const int N=1e6+1;
ll a[N], bit[N];

inline void upd(int i, ll v){
    for(; i<=N; i+=i&-i) 
        bit[i]=min(bit[i], v); //cập nhật ptu (dùng cho min prefix) 
        bit[i]+=v; //cập nhật phần tử
}
inline ll get(int i){ ll ans=9e18;
    for(; i; i-=i&-i)
        ans=min(ans, bit[i]); //lấy min đoạn
        ans+=bit[i]; //lấy tổng đoạn
    return ans;
}
