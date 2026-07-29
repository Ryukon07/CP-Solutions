#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using ll = long long;
const ll INF = 1e18;

void solve() {
    int n; 
    std::cin >> n;
    std::vector<ll> x(n), t(n);

    for (int i = 0; i < n; i++) std::cin >> x[i];
    for (int i = 0; i < n; i++) std::cin >> t[i];

    ll max = -INF;
    ll min = INF;

    for (int i = 0; i < n; i++) {
        max = std::max(max, x[i] + t[i]);
        min = std::min(min, x[i] - t[i]);
    }

    double x0 = (max + min) / 2.0;

    std::cout << std::fixed << std::setprecision(1) << x0 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; 
    std::cin >> t;
    while (t--) solve();

    return 0;
}