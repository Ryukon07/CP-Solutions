#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<ll> max(n + 1, 0);

    for(ll i = 0; i < m; i++){
        ll x, y; std::cin >> x >> y;
        if(x > y) std::swap(x, y);
        max[y] = std::max(max[y], x + 1);
    }

    ll ans = 0, start = 1;
    for(ll b = 1; b <= n; b++){
        start = std::max(start, max[b]);
        ans += b - start + 1;
    }
    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}