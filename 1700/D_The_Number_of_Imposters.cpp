#include <iostream>
#include <vector>

using ll = long long;

struct Edge{
    ll to, type;
};

std::pair<ll, ll> bfs(ll start, std::vector<std::vector<Edge>>& adj, std::vector<ll>& color, bool& possible){
    ll count0 = 0, count1 = 0;
    std::vector<ll> queue;
    queue.push_back(start);
    color[start] = 0;
    count0++;

    while(!queue.empty()){
        ll node = queue.back();
        queue.pop_back();

        for(auto& edge : adj[node]){
            ll v = edge.to;
            ll type = edge.type;

            ll exp = (type == 0) ? color[node] : (1 - color[node]);

            if(color[v] == -1){
                color[v] = exp;
                if(exp == 0) count0++;
                else count1++;
                queue.push_back(v);
            } else {
                if(color[v] != exp){
                    possible = false;
                }
            }
        }
    }
    return {count0, count1};
}

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<std::vector<Edge>> adj(n + 1);
    std::vector<ll> color(n + 1, -1);

    for(ll i = 0; i < m; i++){
        ll u, v; std::cin >> u >> v;
        std::string s; std::cin >> s;

        ll type = (s == "crewmate") ? 0 : 1;
        adj[u].push_back({v, type});
        adj[v].push_back({u, type});
    }

    ll max = 0;
    bool possible = true;

    for(ll i = 1; i <= n; i++){
        if(color[i] == -1){
            auto [c0, c1] = bfs(i, adj, color, possible);
            if(!possible){
                std::cout << -1 << "\n";
                return;
            }
            max += std::max(c0, c1);
        }
    }
    std::cout << max << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}