#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using ll = long long;

bool check(ll k, ll n, const std::vector<ll>& a) {
    ll g = 0;
    for (ll i = 0; i < n - k; i++) {
        ll diff = std::abs(a[i] - a[i + k]);
        g = std::gcd(g, diff);

        if(g == 1) return false;

    }
    return (g == 0 || g > 1);
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    ll ans = 0;

    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            if(check(i, n, a)) ans++;
            if(i != n / i && check(n / i, n, a)) ans++;
        }
    }
    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;

}