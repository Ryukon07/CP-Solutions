#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    if(n > m) std::cout << "0\n";
    else{
        ll ans = 1;
        for(ll i = 0; i < n; i++){
            for(ll j = i + 1; j < n; j++){
                ans *= std::abs(a[j] - a[i]);
                ans %= m;
            }
        }
        std::cout << ans << "\n";
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}