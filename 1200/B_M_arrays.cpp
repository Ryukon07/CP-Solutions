#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::vector<ll> rem(m, 0);
    for(ll i = 0; i < n; i++){
        rem[a[i] % m]++;
    }

    ll ans = 0;

    for(ll i = 0; i < m; i++){
        ll x = rem[i], y = rem[(m - i) % m];
        if( x == 0 && y == 0) continue;

        ll pairs = std::min(x, y);
        x -= std::min(pairs + 1, x);
        y -= std::min(pairs + 1, y);

        ans++;
        ans += (x + y);

        rem[i] = 0;
        rem[(m - i) % m] = 0;
    }

    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}