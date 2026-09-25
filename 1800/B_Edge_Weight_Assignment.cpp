#include <iostream>
#include <vector>
#include <set>

using ll = long long;

void dfs(ll node, ll parent, ll d, std::vector<std::vector<ll>>& adj, std::vector<ll>& depth){
    depth[node] = d;
    for(auto& neighbor : adj[node]){
        if(neighbor != parent){
            dfs(neighbor, node, d + 1, adj, depth);
        }
    }
}

void solve(){
    ll n; std::cin >> n;

    std::vector<std::vector<ll>> adj(n + 1);
    std::vector<ll> deg(n + 1, 0);

    for(ll i = 0; i < n - 1; i++){
        ll u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    std::vector<ll> depth(n + 1, 0);
    dfs(1, 0, 0, adj, depth);

    ll leaf = 0, parity = -1;
    bool sameParity = true;
    std::set<ll> leafParents;

    for(ll i = 1; i <= n; i++){
        if(deg[i] == 1){
            leaf++;
            if(parity == -1) parity = depth[i] % 2;
            else if(parity != depth[i] % 2) sameParity = false;
            leafParents.insert(adj[i][0]);
        }
    }

    ll min = sameParity ? 1 : 3;
    ll max = (n - 1) - leaf + leafParents.size();

    std::cout << min << " " << max << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}