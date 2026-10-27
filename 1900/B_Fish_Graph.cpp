#include <iostream>
#include <vector>
#include <queue>

using ll = long long;

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<std::vector<ll>> adj(n + 1);
    for(ll i = 0; i < m; i++){
        ll u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(ll u = 1; u <= n; u++){
        if(adj[u].size() < 4) continue;

        std::vector<ll> root(n + 1, -1), parent(n + 1, -1);
        std::queue<ll> q;

        for(ll v : adj[u]){
            root[v] = v;
            q.push(v);
        }

        ll x = -1, y = -1;

        while(!q.empty() && x == -1){
            ll v = q.front(); q.pop();
            for(ll w : adj[v]){
                if(w == u) continue;
                if(root[w] == -1){
                    root[w] = root[v];
                    parent[w] = v;
                    q.push(w);
                } else if(root[w] != root[v]){
                    x = v; y = w;
                    break;
                }
            }
        }

        if(x == -1) continue;

        ll a = root[x], b = root[y];
        std::vector<std::pair<ll, ll>> ans;
        ans.push_back({x, y});
        for(ll v = x; parent[v] != -1; v = parent[v]) ans.push_back({v, parent[v]});
        for(ll v = y; parent[v] != -1; v = parent[v]) ans.push_back({v, parent[v]});

        ans.push_back({u, a});
        ans.push_back({u, b});

        ll added = 0;
        for(ll v : adj[u]){
            if(v != a && v != b && added < 2){
                ans.push_back({u, v});
                added++;
            }
        }

        std::cout << "YES\n";
        std::cout << ans.size() << "\n";
        for(auto [x, y] : ans) std::cout << x << " " << y << "\n";
        return;
    }
    std::cout << "NO\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}