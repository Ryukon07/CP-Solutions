#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n + 1);
    for(ll i = 1; i <= n; ++i) std::cin >> a[i];

    std::vector<bool> dp(n + 1, false);
    dp[0] = true;

    for(ll i = 1; i <= n; i++){
        ll num = a[i];
        if(i - num - 1 >= 0 && dp[i - num - 1]) dp[i] = true;
        if(dp[i-1] && i + num <= n) dp[i + num] = true;
    }

    if(dp[n]) std::cout << "YES\n";
    else std::cout << "NO\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
}