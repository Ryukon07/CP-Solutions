#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;

    std::vector<std::vector<ll>> adj(n + 1);
    std::vector<bool> visited(n + 1, false);
    std::vector<ll> color(n + 1, -1);

    ll parent = -1;

    for(ll i = 0; i < n; i++){
        ll u, c; std::cin >> u >> c;
        if(u == -1){
            parent = i + 1;
            color[parent] = c;
            continue;
        }
        adj[u].push_back(i + 1);
        adj[i + 1].push_back(u);
        color[i + 1] = c;
    }

    std::vector<ll> ans;

    std::queue<ll> q;
    q.push(parent);
    visited[parent] = true;

    while(!q.empty()){
        bool flag = false;
        ll node = q.front(); q.pop();
        if(color[node] == 1) flag = true;
        for(auto child : adj[node]){
            if(!visited[child]){
                visited[child] = true;
                if(color[child] == 0) flag = false;
                q.push(child);
            }
        }
        if(flag) ans.push_back(node);
    }

    std::sort(ans.begin(), ans.end());

    if(ans.empty()){
        std::cout << "-1\n";
        return;
    }

    for(auto x : ans) std::cout << x << " ";
    std::cout << "\n";

}

int main(){
    solve();
    return 0;
}