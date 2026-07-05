#include <iostream>
#include <vector>
#include <queue>

using ll = long long;

void solve(){
    ll n; std::cin >> n;

    std::vector<std::vector<std::pair<ll, ll>>> adj(n + 1);
    for(ll i = 1; i <= n - 1; i++){
        ll u, v; std::cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    std::vector<ll> pos(n + 1, 0), pass(n + 1, 0);
    std::vector<bool> visited(n + 1, false);

    ll ans = 1;

    std::queue<ll> q;
    q.push(1);
    visited[1] = true;
    pos[1] = 0;
    pass[1] = 1;

    while(!q.empty()){
        ll u = q.front(); q.pop();
        for(auto [v, idx]: adj[u]){
            if(!visited[v]){
                visited[v] = true;
                pos[v] = idx;
                if(idx > pos[u]){
                    pass[v] = pass[u];
                } else {
                    pass[v] = pass[u] + 1;
                }
                ans = std::max(ans, pass[v]);
                q.push(v);
            }
        }
    }

    std::cout << ans << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}