#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
const ll MOD = 1e9 + 7;

void dfs(ll node, ll parent, ll n, const std::vector<std::vector<ll>>& adj, std::vector<ll>& sz, std::vector<ll>& freq) {
    sz[node] = 1;

    for(ll neighbor : adj[node]) {
        if(neighbor == parent) continue;
        dfs(neighbor, node, n, adj, sz, freq);
        sz[node] += sz[neighbor];
        freq.push_back(sz[neighbor] * (n - sz[neighbor]));
    }
    
}

void solve(){
    ll n; std::cin >> n;
    std::vector<std::vector<ll>> adj(n + 1);
    
    for(ll i = 0; i < n - 1; i++){
        ll u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    ll m; std::cin >> m;
    std::vector<ll> b(m);
    for(ll i = 0; i < m; i++) std::cin >> b[i];
    
    std::vector<ll> freq;
    std::vector<ll> sz(n + 1, 0);
    
    dfs(1, -1, n, adj, sz, freq);
    std::sort(freq.begin(), freq.end());
    std::sort(b.begin(), b.end());
    std::vector<ll> factors;

    if(m <= n - 1){
        factors.assign(n - 1 - m, 1);
        for(ll x: b) factors.push_back(x);
    }else{
        for(ll i = 0; i < n - 2; i++) factors.push_back(b[i]);

        ll comb = 1;
        for(ll i = n - 2; i < m; i++) comb = (comb * b[i]) % MOD;
        factors.push_back(comb);
    }

    ll ans = 0;
    for(ll i = 0; i < n - 1; i++){
        ll f = freq[i] % MOD;
        ll p = factors[i] % MOD;
        ans = (ans + (f * p) % MOD) % MOD;
    }

    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}