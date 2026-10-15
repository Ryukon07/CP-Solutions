#include <iostream>
#include <vector>

using ll = long long;

ll n, m, timer;
std::vector<std::vector<ll>> adj;
std::vector<ll> tin, low, subtree;
ll ans; 

void dfs(ll v, ll p){
    tin[v] = low[v] = ++timer;
    subtree[v] = 1;

    for(ll to : adj[v]){
        if(to == p) continue;
        if(tin[to]){
            low[v] = std::min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = std::min(low[v], low[to]);
            subtree[v] += subtree[to];

            if(low[to] > tin[v]){
                ll s = subtree[to];
                ll pairs = s * (s-1) / 2 + (n - s) * (n - s - 1) / 2;
                ans = std::min(ans, pairs);
            }
        }
    }
}

void solve(){
    std::cin >> n >> m;
    adj.assign(n + 1, std::vector<ll>());
    tin.assign(n + 1, 0);
    low.assign(n + 1, 0);
    subtree.assign(n + 1, 0);
    timer = 0;

    ans = 1LL * n * (n - 1) / 2;

    for(ll i = 0; i < m; i++){
        ll u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    std::cout << ans << "\n";
      
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}