#include <iostream>
#include <vector>

using ll = long long;
const ll MOD = 1e9 + 7;
std::vector<ll> power2(200001);

void solve(){
    ll n; std::cin >> n;
    std::vector<std::vector<ll>> adj(n + 1);
    for(ll i = 0; i < n - 1; i++){
        ll u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<ll> parent(n + 1, 0), height(n + 1, 0), order;
    
    order.push_back(1);
    parent[1] = -1;
    for(ll i = 0; i < order.size(); i++){
        ll u = order[i];
        for(ll v: adj[u]){
            if(v == parent[u]) continue;
            parent[v] = u;
            order.push_back(v);
        }
    }

    ll sum = 0;
    for(ll i = n - 1; i >= 0; i--){
        ll u = order[i];
        sum = (sum + height[u] + 1) % MOD;
        if(parent[u] != -1){
            ll p = parent[u];
            height[p] = std::max(height[p], height[u] + 1);
        }
    }

    ll ans = sum * power2[n - 1] % MOD;
    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);   
    std::cin.tie(nullptr);

    power2[0] = 1;
    for(ll i = 1; i < 200001; i++) power2[i] = (power2[i-1] * 2) % MOD;
    
    ll t; std::cin >> t;
    while(t--) solve();

}