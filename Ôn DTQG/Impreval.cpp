// Source: oj.vnoi.info/problem/voi24_impeval

#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll, int>
#pragma GCC target("avx2,bmi2")
#pragma GCC optimize("O3,unroll-loops")
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N = 1e5 + 5;
ll d[N], d2[N]; 
vector<pii> g[N];
pii e[N];

void dijkstra(int s, ll d[]){
    priority_queue<pii> pq;
    pq.push({0, s}); d[s] = 0;

    while(!pq.empty()){
        auto [du, u] = pq.top(); pq.pop();
        if(-du != d[u]) continue;
        for(auto [v, w] : g[u]) if(-du + w < d[v]) {
            d[v] = -du + w; 
            pq.push({du - w, v});
        }
    }
}

// ------------------- CẤU TRÚC PHỤ TRỢ CHO QUÉT ĐƯỜNG -------------------
struct Point {
    ll x, y;
};

struct OfflineQuery {
    ll x, y;
    int id;
    int type; // 0 đại diện cho u1,u2 (cu) | 1 đại diện cho v1,v2 (cv)
};

struct FenwickTree {
    int n;
    vector<int> bit;
    FenwickTree(int n) : n(n), bit(n + 1, 0) {}
    
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
        return sum;
    }
};
// -----------------------------------------------------------------------

void process_queries(int n, int q) {
    vector<OfflineQuery> queries;
    vector<ll> coords; // Nén tọa độ cho giá trị Y (d2 và u2, v2)
    vector<pair<int, int>> ans(q); // Lưu đáp án cuối cùng: {cu, cv}

    // 1. ĐỌC TOÀN BỘ TRUY VẤN (OFFLINE)
    for (int i = 0; i < q; ++i) {
        int t, w;
        cin >> t >> w;
        int u = e[t].first, v = e[t].second;

        ll u1 = min(d[u], d[v] + w);
        ll v1 = min(d[v], d[u] + w);
        ll u2 = min(d2[u], d2[v] + w);
        ll v2 = min(d2[v], d2[u] + w);

        // Đẩy 2 truy vấn con vào mảng
        queries.push_back({u1, u2, i, 0});
        queries.push_back({v1, v2, i, 1});

        // Thêm các tọa độ Y cần thiết để nén
        coords.push_back(u2);
        coords.push_back(v2);

        // Xử lý trước phần bù bên ngoài vòng for (cu+=..., cv+=...)
        ans[i].first = (d[u] > u1 || d2[u] > u2) ? 1 : 0;
        ans[i].second = (d[v] > v1 || d2[v] > v2) ? 1 : 0;
    }

    // 2. CHUẨN BỊ MẢNG ĐIỂM
    vector<Point> pts(n);
    for (int i = 1; i <= n; ++i) {
        pts[i - 1] = {d[i], d2[i]};
        coords.push_back(d2[i]);
    }

    // 3. NÉN TỌA ĐỘ TRỤC Y
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    
    // Hàm lấy vị trí tọa độ đã nén
    auto get_y = [&](ll val) {
        return lower_bound(coords.begin(), coords.end(), val) - coords.begin() + 1;
    };

    // 4. SẮP XẾP ĐIỂM VÀ TRUY VẤN TĂNG DẦN THEO TRỤC X
    sort(pts.begin(), pts.end(), [](const Point &a, const Point &b) {
        return a.x < b.x;
    });
    sort(queries.begin(), queries.end(), [](const OfflineQuery &a, const OfflineQuery &b) {
        return a.x < b.x;
    });

    // 5. QUÉT ĐƯỜNG (SWEEP LINE) + BIT
    FenwickTree bit(coords.size());
    int pt_idx = 0;

    for (const auto &qr : queries) {
        // Đẩy tất cả các điểm có x (hay d[i]) <= qr.x vào BIT
        while (pt_idx < n && pts[pt_idx].x <= qr.x) {
            bit.update(get_y(pts[pt_idx].y), 1);
            pt_idx++;
        }
        
        // Truy vấn số lượng điểm có y <= qr.y
        int cnt = bit.query(get_y(qr.y));
        
        // Cộng kết quả vào đúng biến cu (type 0) hoặc cv (type 1) của truy vấn gốc id
        if (qr.type == 0) ans[qr.id].first += cnt;
        else ans[qr.id].second += cnt;
    }

    // 6. IN KẾT QUẢ THEO ĐÚNG THỨ TỰ
    for (int i = 0; i < q; ++i) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("IMPEVAL.INP", "r", stdin);
    //freopen("IMPEVAL.OUT", "w", stdout);

    int n, m, q, u, v, w;
    cin >> n >> m >> q;

    fo(i, 1, m) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        e[i] = {u, v};
    }
    memset(d, 0x3f, sizeof d);
    memset(d2, 0x3f, sizeof d2);
    
    dijkstra(1, d); 
    dijkstra(2, d2);
    process_queries(n, q);
}
