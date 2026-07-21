#include <iostream>
#include <vector>

using ll = long long;

void numberOfNodes(ll node, ll parent, const std::vector<std::vector<ll>>& adj, std::vector<ll>& subtreeSize) {
    subtreeSize[node] = 1;

    for (ll neighbor : adj[node]) {
        if (neighbor != parent) {
            numberOfNodes(neighbor, node, adj, subtreeSize);
            subtreeSize[node] += subtreeSize[neighbor];
        }
    }
}

void solve(){
    ll n; std::cin >> n;

    if(n % 2) {
        std::cout << "-1\n";
        return;
    }

    std::vector<std::vector<ll>> adj(n + 1);
    std::vector<ll> subtreeSize(n + 1, 0);

    for(ll i = 0; i < n - 1; i++){
        ll u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    numberOfNodes(1, 0, adj, subtreeSize);

    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        if(subtreeSize[i] % 2 == 0 ) {
            ans++;
        }
    }
    std::cout << ans - 1 << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}