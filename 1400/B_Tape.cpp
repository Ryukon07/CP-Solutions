#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n, m, k; std::cin >> n >> m >> k;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::vector<ll> diff;
    for(ll i = 1; i < n; i++){
        diff.push_back(a[i] - a[i - 1]);
    }
    std::sort(diff.begin(), diff.end());

    ll ans = 0;

    ll t = n - k;
    for(ll i = 0; i < t; i++){
        ans += diff[i];
    }

    ans += k;

    std::cout << ans << "\n";

}

int main(){
    solve();
    return 0;
}