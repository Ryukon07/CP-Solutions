#include <iostream>
#include <vector>

using ll = long long;
const ll INF = 1e18;

std::vector<ll> dp(1001, INF);

void solve(){
    ll n, k; std::cin >> n >> k;
    k = std::min(k, 12 * n);

    std::vector<ll> b(n), c(n);
    for(ll i = 0; i < n; i++) std::cin >> b[i];
    for(ll i = 0; i < n; i++) std::cin >> c[i];

    std::vector<ll> ans(k + 1, 0);

    for(ll i = 0; i < n; i++){
        ll weight = dp[b[i]];
        ll cost = c[i];

        for(ll j = k; j >= weight; j--){
            ans[j] = std::max(ans[j], cost + ans[j - weight]);
        }

    }

    ll max = 0;
    for(ll i = 0; i <= k; i++) max = std::max(max, ans[i]);

    std::cout << max << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    dp[1] = 0;
    for(ll i = 1; i <= 1000; i++){
        for(ll j = 1; j <= i; j++){
            ll tmp = i + (i / j);
            if(tmp <= 1000) dp[tmp] = std::min(dp[tmp], dp[i] + 1);
        }
    }

    ll t; std::cin >> t;
    while(t--) solve();

}