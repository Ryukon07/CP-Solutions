#include <iostream>
#include <vector>

using ll = long long;
const ll MOD = 1e9 + 7;

void solve(){
    ll n, k; std::cin >> n >> k;
    std::vector<std::vector<ll>> dp(k + 1, std::vector<ll>(n + 1, 0));
    for(ll i = 1; i <= n; i++) dp[1][i] = 1;

    for(ll i = 2; i <= k; i++){
        for(ll j = 1; j <= n; j++){
            for(ll l = j; l <= n; l += j){
                dp[i][j] += dp[i - 1][l];
                dp[i][j] %= MOD;
            }
        }
    }

    ll ans = 0;
    for(ll i = 1; i <= n; i++) ans += dp[k][i] % MOD;
    ans %= MOD;

    std::cout << ans << "\n";

}

int main(){
    solve();
    return 0;
}