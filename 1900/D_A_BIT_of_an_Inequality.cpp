#include <iostream>
#include <vector>

using ll = long long;
std::vector<ll> pref;
std::vector<std::vector<ll>> dp;

ll recur(ll i, ll bit){
    if(i < 0) return 0;
    if(dp[bit][i] != -1) return dp[bit][i];
    return dp[bit][i] = ((pref[i] >> bit) & 1) + recur(i - 1, bit);
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n + 1);
    dp.assign(30, std::vector<ll>(n + 1, -1));
    pref.assign(n + 1, 0);
    for(ll i = 1; i <= n; i++){
        std::cin >> a[i];
        pref[i] = pref[i - 1] ^ a[i];
    };

    ll ans = 0;
    for(ll y = 1; y <= n; y++){
        ll bit = 63 - __builtin_clzll(a[y]);

        ll l1 = recur(y - 1, bit);
        ll r1 = recur(n, bit) - l1;

        ll l0 = y - l1;
        ll r0 = (n - y + 1) - r1;

        ans += (l0 * r0) + (l1 * r1);
    }

    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}