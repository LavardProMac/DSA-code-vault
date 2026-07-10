// Source: gspvh2627.contest.codeforces.com/group/GXYpZfKThs/contest/702381/problem/O

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Tối ưu I/O trong C++ để đọc ghi nhanh hơn
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("towers.inp", "r", stdin);
    freopen("towers.out", "w", stdout);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> h(n + 1);
    vector<long long> sum(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        sum[i] = sum[i - 1] + h[i];
    }

    // Hàm lambda tính tổng một đoạn [L, R]
    auto getSum = [&](int L, int R) -> long long {
        if (L > R) return 0;
        return sum[R] - sum[L - 1];
    };

    // Khởi tạo mảng F. Dùng kiểu short để tiết kiệm bộ nhớ (9000x9000 short ~ 162MB)
    // Giá trị khởi tạo là -1
    vector<vector<short>> F(n + 1, vector<short>(n + 1, -1));

    // Base case: Cả đoạn [1..r] là 1 phân đoạn duy nhất
    for (int r = 1; r <= n; ++r) {
        F[1][r] = 1;
    }

    // Tính toán QHĐ
    for (int l = 2; l <= n; ++l) {
        int k = l - 1;
        short best = -1;
        
        for (int r = l; r <= n; ++r) {
            long long current_sum = getSum(l, r);
            
            // Đẩy k về bên trái nếu thoả mãn điều kiện tổng
            while (k >= 1 && getSum(k, l - 1) < current_sum) {
                if (F[k][l - 1] != -1) {
                    best = max(best, F[k][l - 1]);
                }
                k--;
            }
            
            if (best != -1) {
                F[l][r] = best + 1;
            }
        }
    }

    // Tìm số phân đoạn lớn nhất kết thúc tại vị trí n
    short max_segments = -1;
    for (int l = 1; l <= n; ++l) {
        max_segments = max(max_segments, F[l][n]);
    }

    // Kết quả là: Tổng số phần tử - Số phân đoạn tối đa
    cout << n - max_segments << "\n";

    return 0;
}
