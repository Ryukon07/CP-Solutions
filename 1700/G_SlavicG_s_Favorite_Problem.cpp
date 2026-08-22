#include <iostream>
#include <vector>
#include <set>

using ll = long long;

void dfs_Start(ll node, ll parent, std::vector<std::vector<std::pair<ll, ll>>>& adj, std::set<ll>& a, bool& check, ll start, ll end, ll currentXOR){
    if(node == end) return;
    a.insert(currentXOR);

    for(auto& [neighbor, weight] : adj[node]){
        if(neighbor == parent) continue;
        dfs_Start(neighbor, node, adj, a, check, start, end, currentXOR ^ weight);
    }
}

void dfs_End(ll node, ll parent, std::vector<std::vector<std::pair<ll, ll>>>& adj, std::set<ll>& a, bool& check, ll start, ll end, ll currentXOR){
    for(auto& [neighbor, weight] : adj[node]){
        if(neighbor == parent) continue;
        ll newXOR = currentXOR ^ weight;
        if(a.find(newXOR) != a.end()){
            check = true;
            return;
        }
        dfs_End(neighbor, node, adj, a, check, start, end, newXOR);
    }
}

void solve(){
    ll n, s, e; std::cin >> n >> s >> e;
    std::vector<std::vector<std::pair<ll, ll>>> adj(n + 1);
    for(ll i = 0; i < n - 1; ++i) {
        ll u, v, w; std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    bool check = false;
    std::set<ll> a;

    dfs_Start(s, -1, adj, a, check, s, e, 0);
    dfs_End(e, -1, adj, a, check, s, e, 0);

    if(check) std::cout << "YES\n";
    else std::cout << "NO\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}