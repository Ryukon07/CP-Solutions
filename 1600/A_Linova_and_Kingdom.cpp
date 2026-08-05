#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using ll = long long;

void dfs(ll start, ll parent, ll d, const std::vector<std::vector<ll>>& adj, std::vector<ll>& depth, std::vector<ll>& size) {
    depth[start] = d;
    size[start] = 1;

    for(auto v: adj[start]){
        if(v != parent){
            dfs(v, start, d + 1, adj, depth, size);
            size[start] += size[v];
        }
    }
}

void solve(){
    ll n, k; std::cin >> n >> k;
    std::vector<std::vector<ll>> adj(n + 1);
    for(ll i = 0; i < n - 1; i++){
        ll u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<ll> depth(n + 1, 0), size(n + 1, 0);

    dfs(1, 0, 0, adj, depth, size);

    std::vector<ll> contri(n, 0);

    for(ll i = 1; i <= n; i++) contri[i - 1] = depth[i] - (size[i] - 1);
    

    std::sort(contri.begin(), contri.end(), std::greater<ll>());

    ll ans = 0;
    for(ll i = 0; i < k; i++) ans += contri[i];

    std::cout << ans << "\n";


}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

    return 0;
}