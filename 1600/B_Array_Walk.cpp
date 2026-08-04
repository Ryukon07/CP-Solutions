#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, k, z; std::cin >> n >> k >> z;

    std::vector<ll> a(n + 1, 0);
    for(ll i = 1; i <= n; i++) std::cin >> a[i];

    std::vector<ll> maxPair(n + 1, 0);
    for(ll i = 2; i <= n; i++) maxPair[i] = std::max(maxPair[i - 1], a[i] + a[i - 1]);

    std::vector<ll> prefix(n + 1, 0);
    for(ll i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + a[i];

    ll ans = 0;
    for(ll i = 0; i <= z; i++){
        ll moves = k - 2 * i;
        if(moves < 0) break;

        ll idx = std::min(n, moves + 2);
        ll current = prefix[moves + 1] + maxPair[idx] * i;
        ans = std::max(ans, current);
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