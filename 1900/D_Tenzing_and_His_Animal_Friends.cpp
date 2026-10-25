#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using ll = long long;
const ll INF = 1e18;

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<std::vector<std::pair<ll, ll>>> adj(n + 1);
    for(ll i = 0; i < m; i++){
        ll u, v, w; std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    std::vector<ll> dist(n + 1, INF);

    std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll>>, std::greater<std::pair<ll, ll>>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;
        for(auto [v, w] : adj[u]){
            if(d + w < dist[v]){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    if(dist[n] == INF){
        std::cout << "inf\n";
        return;
    }

    ll T = dist[n];
    std::vector<ll> times = {0, T};
    for(ll i = 1; i < n; i++) if(dist[i] < T) times.push_back(dist[i]);
    

    std::sort(times.begin(), times.end());
    times.erase(std::unique(times.begin(), times.end()), times.end());
    std::vector<std::pair<std::string, ll>> ans;
    
    for(ll i = 0; i + 1 < times.size(); i++){
        std::string s(n, '0');
        for(ll j = 1; j < n; j++) if(dist[j] <= times[i]) s[j - 1] = '1';

        ans.push_back({s, times[i + 1] - times[i]});
    }

    std::cout << T << " " << ans.size() << "\n";
    for(auto [s, t] : ans) std::cout << s << " " << t << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}