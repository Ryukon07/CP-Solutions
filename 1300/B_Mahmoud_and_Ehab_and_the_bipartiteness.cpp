#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<std::vector<ll>> adj(n + 1);
    for(ll i = 0; i < n - 1; i++){
        ll u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<ll> color(n + 1, -1);
    ll cnts[2] = {0, 0};
    std::vector<ll> stack = {1};
    color[1] = 1;
    cnts[1] = 1;

    while(!stack.empty()){
        ll u = stack.back(); stack.pop_back();
        for(ll v : adj[u]){
            if(color[v] == -1){
                color[v] = 1 ^ color[u];
                cnts[color[v]]++;
                stack.push_back(v);
            }
        }
    }

    std::cout << cnts[0] * cnts[1] - (n - 1) << "\n";

}

int main(){
    solve();
}