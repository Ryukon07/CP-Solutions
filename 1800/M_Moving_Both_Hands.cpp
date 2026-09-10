#include <iostream>
#include <vector>
#include <queue>

using ll = long long;
const ll INF = 1e18;

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<std::vector<std::pair<ll, ll>>> adj(2 * n + 1);

    for(ll i = 0; i < m; i++){
        ll u, v, w; std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v + n].push_back({u + n, w});
    }

    for(ll i = 1; i <= n; i++) adj[i].push_back({i + n, 0});

    std::vector<ll> dist(2 * n + 1, INF);
    std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll>>, std::greater<std::pair<ll, ll>>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;

        for(auto [v, w] : adj[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for(ll i = 2; i <= n; i++){
        if(dist[i + n] == INF) std::cout << -1 << " ";
        else std::cout << dist[i + n] << " ";
    }

    std::cout << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}