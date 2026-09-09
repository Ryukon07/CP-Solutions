#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

std::vector<std::vector<ll>> adj;

std::pair<ll, ll> dfs(ll node, ll parent, ll dist = 0){
    std::pair<ll, ll> best = {dist, node};
    for(ll child: adj[node]) if(child != parent) best = std::max(best, dfs(child, node, dist + 1));
    
    return best;
}

void dist(ll node, ll parent, ll dista, std::vector<ll>& maxDist){
    maxDist[node] = std::max(maxDist[node], dista);
    for(ll child: adj[node]) if(child != parent) dist(child, node, dista + 1, maxDist);  
}

void solve(){
    ll n; std::cin >> n;
    adj.assign(n + 1, std::vector<ll>());

    for(ll i = 0; i < n - 1; i++){
        ll u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto res1 = dfs(1, -1);
    ll A = res1.second;
    
    auto res2 = dfs(A, -1);
    ll D = res2.first;
    ll B = res2.second;

    std::vector<ll> maxDist(n + 1, 0);
    dist(A, -1, 0, maxDist);
    dist(B, -1, 0, maxDist);

    std::sort(maxDist.begin(), maxDist.end());

    for(ll i = 1; i <= n; i++){
        ll idx = std::lower_bound(maxDist.begin(), maxDist.end(), i) - maxDist.begin();
        std::cout << std::min(n, idx) << (i == n ? "" : " ");
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}