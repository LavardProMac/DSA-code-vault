// Đề: Cho x + y + z = n và 3 mảng a[n], b[n], c[n]
// Chọn x số từ a, y số từ b và z số từ c thỏa mãn:
// - không có 2 số nào trùng chỉ số
// - tổng tất cả các số được chọn là lớn nhất

// Biến đổi bài toán:
// Chọn toàn bộ a[n] và b[i]-=a[i], c[i]-=a[i]
// => Loại bỏ việc chọn a, chỉ cần chọn y số từ b và z số từ c

// Quan tâm: Với 2 chỉ số i và j thì chọn b[i], c[j] hay chọn b[j], c[i]?
// Cần biết b[i]+c[j] và b[j]+c[i] cái nào lớn hơn
// <=> so sánh b[i]-c[i] và b[j]-c[j]

// Với mọi i<j: b[i]-c[i] <= b[j]-c[j] <=> b[i]+c[j] <= b[j]+c[i]
// => Chọn các số trong c có chỉ số nhỏ, b có chỉ số lớn

// Cần đảm bảo: max(idx c) < min(idx b)
// => Tính max(pre i, suf i+1)

// Dùng multiset/ priority_queue để tính
// ĐPT: O(N log N)

#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define f first
#define s second
#define fo(i,j,n) for(int i=j; i<=n; ++i)
#define fd(i,j,n) for(int i=j; i>=n; --i)
using namespace std;
const int N=1e5+5;

ll pre[N], suf[N]; pll v[N];
// pre[i]: tổng z số c có tổng max trong đoạn c[1...i]
// suf[i]: tổng y số b có tổng max trong đoạn b[i...n]

inline bool cmp(pll x, pll y){
    // sort theo hiệu b-c tăng dần
	return x.f-x.s<y.f-y.s;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int x, y, z; cin>>x>>y>>z;
	int n=x+y+z; ll ans=0, a, b, c;

	fo(i,1,n) cin>>a>>b>>c,
		ans+=a, v[i]={b-a, c-a};
	
	sort(v+1, v+n+1, cmp);
	multiset<ll> s; ll sum=0;

	fo(i,1,z) sum+=v[i].s,
		s.insert(v[i].s);
	pre[z]=sum;
    
    // lưu tổng z phần tử lớn nhất trong c[1..i]
	fo(i,z+1,z+x){
		s.insert(v[i].s);
		sum+=v[i].s;

		pre[i]=(sum-=*s.begin());
		s.erase(s.begin());
	}
	ll mx=sum=0; s.clear();

	fd(i,n,n-y+1) sum+=v[i].f,
		s.insert(v[i].f);
	suf[n-y+1]=sum;
    
    // lưu tổng y phần tử lớn nhất trong b[i..n]
	fd(i,n-y,x+1){
		s.insert(v[i].f);
		sum+=v[i].f;
		auto it=s.begin();

		suf[i]=(sum-=*it);
		s.erase(it);
	}
	fo(i,z,z+x)
	    mx=max(mx, pre[i]+suf[i+1]);
	cout<<ans+mx;
}
