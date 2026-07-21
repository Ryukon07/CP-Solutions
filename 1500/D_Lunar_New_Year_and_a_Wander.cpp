#include <iostream>
#include <vector>
#include <queue>

using ll = long long;

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<std::vector<ll>> adj(n + 1);

    for(ll i = 0; i < m; ++i){
        ll u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<bool> visited(n + 1, false);
    std::vector<ll> ans; 

    ans.push_back(1);
    visited[1] = true;

    std::priority_queue<ll, std::vector<ll>, std::greater<ll>> pq;
    for(ll i = 0; i < adj[1].size(); ++i){
        pq.push(adj[1][i]);
    }

    while(!pq.empty()){
        ll u = pq.top(); pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        ans.push_back(u);
        for(ll i = 0; i < adj[u].size(); ++i){
            if(!visited[adj[u][i]]){
                pq.push(adj[u][i]);
            }
        }
    }

    for(ll i = 0; i < ans.size(); ++i){
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}