#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, k, a, b; std::cin >> n >> k >> a >> b;
    std::vector<ll> x(n + 1), y(n + 1);
    for(ll i = 1; i <= n; i++){
        std::cin >> x[i] >> y[i];
    }

    ll ans = std::abs(x[a] - x[b]) + std::abs(y[a] - y[b]);
    ll minx = 1e17, miny = 1e17;
    for(ll i = 1; i <= k; i++){
        minx = std::min(minx, std::abs(x[a] - x[i]) + std::abs(y[a] - y[i]));
        miny = std::min(miny, std::abs(x[b] - x[i]) + std::abs(y[b] - y[i]));
    }

    ans = std::min(ans, minx + miny);
    std::cout << ans << "\n";
}


int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}