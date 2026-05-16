#include <iostream>
#include <vector>   

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n), prefixSum(n);
    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        prefixSum[i] = a[i] + (i > 0 ? prefixSum[i - 1] : 0);
    }

    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        if(n % i) continue;
        ll max = prefixSum[i - 1], min = prefixSum[i - 1];
        ll start = i - 1;

        for(ll j = start + i; j < n; j += i){
            ll cur = prefixSum[j] - prefixSum[j - i];
            max = std::max(max, cur);
            min = std::min(min, cur);
        }
        ans = std::max(ans, max - min);
    }
    std::cout << ans << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}