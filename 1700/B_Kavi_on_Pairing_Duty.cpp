#include <iostream>
#include <vector>

using ll = long long;
const ll MOD = 998244353;


void solve(){
    ll n; std::cin >> n;
    std::vector<ll> dp(n + 1, 0);
    std::vector<ll> divisors(n + 1, 0);

    for(ll i = 1; i <= n; i++){
        for(ll j = i; j <= n; j += i){
            divisors[j]++;
        }
    }

    dp[0] = 0;
    ll sum = 0;
    for(ll i = 1; i <= n; i++){
        dp[i] = (sum + divisors[i]) % MOD;
        sum = (sum + dp[i]) % MOD;
    }

    std::cout << dp[n] << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}