#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;

    std::vector<ll> freq(n + 1, 0);
    std::vector<std::vector<std::pair<ll, ll>>> adj(n + 1);

    for(ll i = 0; i < n; i++){
        ll u, v; std::cin >> u >> v;
        freq[u]++; freq[v]++;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for(ll i = 1; i <= n; i++){
        if(freq[i] != 2){
            std::cout << "NO" << "\n";
            return;
        }
    }

    std::vector<bool> visited(n, false);

    for(ll i = 1; i <= n; i++){
        for(auto edge: adj[i]){
            ll next = edge.first;
            ll index = edge.second;

            if(visited[index]) continue;

            ll len = 0;
            ll curr = i;

            while(true){
                ll chosenEdge = -1;
                ll nextNode = -1;

                for(auto e: adj[curr]){
                    if(!visited[e.second]){
                        chosenEdge = e.second;
                        nextNode = e.first;
                        break;
                    }
                }

                if(chosenEdge == -1) break;

                visited[chosenEdge] = true;
                len++;
                curr = nextNode;
            }

            if(len % 2 != 0){
                std::cout << "NO" << "\n";
                return;
            }

        }
    }

    std::cout << "YES" << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}