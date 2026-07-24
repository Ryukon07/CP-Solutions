#include <iostream>
#include <vector>
#include <set>

using ll = long long;

ll find(ll u, std::vector<ll> &parent){
    if(parent[u] == -1) return u;
    return parent[u] = find(parent[u], parent);
}

void merge(ll u, ll v, std::vector<ll> &parent){
    u = find(u, parent);
    v = find(v, parent);
    if(u != v) parent[u] = v;
}

void solve(){
    ll n; std::cin >> n;
    std::set<std::pair<ll, ll>> s;

    for(ll i = 1; i <= n; i++){
        ll v; std::cin >> v;
        ll u = i;
        if(u < v) std::swap(u, v);
        s.insert({u, v});
    }

    std::vector<std::vector<ll>> adj(n + 1);
    for(auto [u, v] : s){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<bool> visited(n + 1, false);
    std::vector<ll> parent(n + 1, -1);
    std::vector<bool> hasCycle(n + 1, false);

    for(auto [u, v] : s){
        ll rootU = find(u, parent);
        ll rootV = find(v, parent);
        if(rootU == rootV) {
            hasCycle[rootU] = true;
        } else {
            bool cycle = hasCycle[rootU] || hasCycle[rootV];
            merge(u, v, parent);
            hasCycle[find(u, parent)] = cycle;
        }
    }

    ll close = 0, open = 0;
    for(ll i = 1; i <= n; i++){
        if(parent[i] == -1) {
            if(hasCycle[i]) close++;
            else open++;
        }
    }

    ll min = close + (open > 0 ? 1 : 0);
    ll max = close + open;

    std::cout << min << " " << max << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    ll t; std::cin >> t;
    while(t--) solve();
    return 0;

}