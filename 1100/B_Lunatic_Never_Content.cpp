#include <iostream>
#include <vector>
#include <numeric>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ans = std::gcd(ans, std::abs(a[i] - a[n - i - 1]));
    }
    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}