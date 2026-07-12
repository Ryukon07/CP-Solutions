#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::vector<ll> dp(n + 1, 0);
    for(ll i = n - 1; i >= 0; i--){
        ll tmp = 1 + dp[i + 1];
        if(i + a[i] + 1 <= n) dp[i] = std::min(tmp, dp[i + a[i] + 1]);
        else dp[i] = tmp;
    }
    std::cout << dp[0] << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}