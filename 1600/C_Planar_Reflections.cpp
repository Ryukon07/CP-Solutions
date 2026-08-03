#include <iostream>
#include <vector>

using ll = long long;
const ll MOD = 1e9 + 7;


void solve(){
    ll n, k; std::cin >> n >> k;
    std::vector<std::vector<ll>> dp(k + 1, std::vector<ll>(n + 1, 0));

    for(ll j = 0; j <= n; j++) dp[1][j] = 1;
    for(ll i = 1; i <= k; i++) dp[i][0] = 1;

    for(ll i = 2; i <= k; i++){
        for(ll j = 1; j <= n; j++){
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][n -j]) % MOD;
        }
    }
    std::cout << dp[k][n] << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}