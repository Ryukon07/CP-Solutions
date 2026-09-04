#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using ll = long long;

struct Edge{
    ll v, w;
};

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<std::vector<Edge>> graph(n + 1);
    for(ll i = 0; i < m; i++){
        ll u, v, w; std::cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    std::vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i++) std::cin >> a[i];

    std::vector<std::vector<ll>> dist(n + 1, std::vector<ll>(1001, 1e18));
    std::vector<std::vector<bool>> visited(n + 1, std::vector<bool>(1001, false));

    using State = std::pair<ll, std::pair<ll, ll>>;
    std::priority_queue<State, std::vector<State>, std::greater<State>> q;

    dist[1][a[1]] = 0;
    q.push({0, {1, a[1]}});

    while(!q.empty()){
        auto [time, state] = q.top(); q.pop();
        auto [u, speed] = state;

        ll eff = std::min(speed, a[u]);

        if(time > dist[u][speed]) continue;

        for(auto [v, w] : graph[u]){
            ll newTime = time + w * eff;
            ll newSpeed = std::min(eff, a[v]);

            if(newTime < dist[v][newSpeed]){
                dist[v][newSpeed] = newTime;
                q.push({newTime, {v, newSpeed}});
            }
        }
    }

    ll ans = *std::min_element(dist[n].begin(), dist[n].end());
    std::cout << ans << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}