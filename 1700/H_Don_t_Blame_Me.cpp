#include <iostream>
#include <vector>

using ll = long long;
const ll MOD = 1e9 + 7;
void add(ll& a, ll b){a += (b % MOD); a %= MOD;}

void solve(){
    ll n, k; std::cin >> n >> k;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; ++i) std::cin >> a[i];

    std::vector<std::vector<ll>> dp(n, std::vector<ll>(64, 0));

    for(ll i = 0; i < n; i++){
        if(i) for(ll j = 0; j < 64; j++) {
            add(dp[i][j], dp[i - 1][j]);
            add(dp[i][j & a[i]], dp[i - 1][j]);
        }
        add(dp[i][a[i]], 1);
    }

    ll ans = 0;
    for(ll i = 0; i < 64; i++) if(__builtin_popcount(i) == k) add(ans, dp[n - 1][i]);

    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
}