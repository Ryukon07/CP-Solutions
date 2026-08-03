#include <iostream>
#include <vector>

using ll = long long;

void dfs(ll node, ll parent, const std::vector<std::vector<ll>>& adj, const std::vector<std::pair<ll, ll>>& range, std::vector<std::vector<ll>>& dp) {
    dp[node][0] = 0;
    dp[node][1] = 0;

    for (ll child : adj[node]) {
        if (child == parent) continue;

        dfs(child, node, adj, range, dp);

        dp[node][0] += std::max(dp[child][0] + std::abs(range[node].first - range[child].first),
                                dp[child][1] + std::abs(range[node].first - range[child].second));

        dp[node][1] += std::max(dp[child][0] + std::abs(range[node].second - range[child].first),
                                dp[child][1] + std::abs(range[node].second - range[child].second));
    }
}

void solve(){
    ll n; std::cin >> n;
    std::vector<std::vector<ll>> adj(n + 1);
    std::vector<std::pair<ll, ll>> range(n + 1);

    for(ll i = 0; i < n; i++) {
        ll l, r; std::cin >> l >> r;
        range[i + 1] = {l, r};
    }

    for(ll i = 0; i < n - 1; i++) {
        ll u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(2, 0));

    dfs(1, 0, adj, range, dp);

    std::cout << std::max(dp[1][0], dp[1][1]) << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;
}