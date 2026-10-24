#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n), b(n);
    
    for(ll i = 0; i < n; i++) std::cin >> a[i];
    for(ll i = 0; i < n; i++) std::cin >> b[i];
    
    ll total = 0;
    ll maxL = -1e18, minR = 1e18;
    for(ll i = 0; i < n; i++){
        total += std::abs(a[i] - b[i]);
        maxL = std::max(maxL, std::min(a[i], b[i]));
        minR = std::min(minR, std::max(a[i], b[i]));
    }

    std::cout << total + 2 * std::max(0LL, maxL - minR) << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;

}