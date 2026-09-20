#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
const ll INF = 1e18;

ll recur(ll i, ll time, const std::vector<ll>& t, std::vector<std::vector<ll>>& dp){
    ll n = t.size();

    if(i == n) return 0;
    if(time > 2 * n) return INF;
    if(dp[i][time] != -1) return dp[i][time];

    ll skip = recur(i, time + 1, t, dp);
    ll take = std::abs(time - t[i]) + recur(i + 1, time + 1, t, dp);

    return dp[i][time] = std::min(skip, take);
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];
    
    std::sort(a.begin(), a.end());

    std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(2 * n + 2, -1));
    std::cout << recur(0, 1, a, dp) << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}