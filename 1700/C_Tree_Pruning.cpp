#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void dfs(ll node, ll parent, ll d, std::vector<std::vector<ll>> &adj, std::vector<ll> &depth, std::vector<ll> &maxDepth){
    depth[node] = d;
    maxDepth[node] = d;
    for(ll neighbor : adj[node]){
        if(neighbor != parent){
            dfs(neighbor, node, d+1, adj, depth, maxDepth);
            maxDepth[node] = std::max(maxDepth[node], maxDepth[neighbor]);
        }
    }
}

void solve(){
    ll n; std::cin >> n;
    std::vector<std::vector<ll>> adj(n);
    for(ll i = 0; i < n-1; i++){
        ll u, v; std::cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<ll> depth(n, 0);
    std::vector<ll> maxDepth(n, 0);
    dfs(0, -1, 0, adj, depth, maxDepth);

    std::vector<ll> diff(n + 2, 0);
    
    for(ll i = 0; i < n; i++){
        diff[depth[i]]++;
        diff[maxDepth[i] + 1]--;
    }

    ll total = 0, curr = 0;
    for(ll i = 0; i <= n; i++){
        curr += diff[i];
        total = std::max(total, curr);
    }

    std::cout << n - total << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}