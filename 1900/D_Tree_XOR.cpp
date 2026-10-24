#include <iostream>
#include <vector>

using ll = long long;
ll n;
std::vector<ll> arr, sz, ans;
std::vector<std::vector<ll>> adj;

void dfs1(ll u, ll p){
    sz[u] = 1;
    for(ll v : adj[u]){
        if(v == p) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        ans[0] += (arr[u] ^ arr[v]) * sz[v];
    }
}

void dfs2(ll u, ll p){
    for(ll v : adj[u]){
        if(v == p) continue;
        ans[v] = ans[u] + (arr[u] ^ arr[v]) * (n - 2 * sz[v]);
        dfs2(v, u); 
    }
}

void solve(){
    std::cin >> n;
    arr.resize(n);
    adj.assign(n, std::vector<ll>());
    sz.assign(n, 0);
    ans.assign(n, 0);
    for(ll i = 0; i < n; i++) std::cin >> arr[i];
    for(ll i = 0; i < n - 1; i++){
        ll u, v; std::cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(0, -1);
    dfs2(0, -1);

    for(ll i = 0; i < n; i++) std::cout << ans[i] << " ";
    std::cout << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
}