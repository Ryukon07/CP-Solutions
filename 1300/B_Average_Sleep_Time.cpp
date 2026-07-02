#include <iostream>
#include <vector>
#include <iomanip>

using ll = long long;

void solve(){
    ll n, k; std::cin >> n >> k;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    ll weeks = n - k + 1;
    ll m = std::min(k, weeks);
    ll sum = 0;

    for(ll i = 0; i < m - 1; i++){
        sum += (i + 1) *(a[i] + a[n - 1 - i]);
    }

    for(ll i = m - 1; i <= n - m; i++){
        sum += m * a[i];
    }

    double ans = (double)sum / weeks;

    std::cout << std::fixed << std::setprecision(10) << ans << "\n";

}

int main(){
    solve();
}