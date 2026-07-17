#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    ll total = 0;
    for(ll i = 0; i < n; i++) std::cin >> a[i], total += a[i];

    std::vector<std::vector<ll>> adj(n + 1);
    for(ll i = 0; i < n - 1; i++){
        ll u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<std::pair<ll, ll>> list;

    for(ll v = 1; v <= n; v++){
        if(adj[v].size() > 1) list.push_back({a[v - 1], (ll)adj[v].size() - 1});
    }

    std::sort(list.rbegin(), list.rend());

    ll ans = total;

    std::cout << ans << " ";
    for(auto &[val, cnt]: list){
        for(ll i = 0; i < cnt; i++){
            ans += val;
            std::cout << ans << " ";
        }
    }
    std::cout << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}