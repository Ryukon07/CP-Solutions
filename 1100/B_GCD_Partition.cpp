#include <iostream>
#include <vector>
#include <numeric>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n), prefixSum(n);
    ll totalSum = 0;
    for(ll i = 0; i < n; i++){
        ll x; std::cin >> x;
        a[i] = x;
        prefixSum[i] = x + (i > 0 ? prefixSum[i - 1] : 0);
        totalSum += x;
    }

    ll ans = 0;
    for(ll i = 0; i < n-1; i++){
        ans = std::max(ans, std::gcd(totalSum - prefixSum[i], prefixSum[i]));
    }
    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}