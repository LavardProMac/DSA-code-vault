#include <bits/stdc++.h>
using namespace std;

int main() {
    int k; cin >> k;
    vector<char> d(k);
    for(auto &x : d) cin >> x;
    long long n; cin >> n;

    int len = 0;
    long long sum = 0, prev = 0;
    while (sum < n) {
        len++;
        prev = sum;
        sum += pow(k, len);
    }
    n -= prev + 1;

    string res;
    for (int i = 0; i < len; i++) {
        res += d[n % k];
        n /= k;
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
}
