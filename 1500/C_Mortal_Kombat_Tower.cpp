#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::vector<std::vector<ll>> dp(n + 2, std::vector<ll>(2, 0));

    for(ll i = n - 1; i >= 0; i--){
        // Friends turn
        ll opt1 = a[i] + dp[i + 1][1];
        if(i + 1 < n){
            ll opt2 = a[i] + a[i + 1] + dp[i + 2][1];
            dp[i][0] = std::min(opt1, opt2);
        } else {
            dp[i][0] = opt1;
        }

        // My turn
        ll opt1_my = dp[i + 1][0];
        if(i + 1 < n){
            ll opt2_my = dp[i + 2][0];
            dp[i][1] = std::min(opt1_my, opt2_my);
        } else {
            dp[i][1] = opt1_my;
        }
    }

    std::cout << dp[0][0] << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}