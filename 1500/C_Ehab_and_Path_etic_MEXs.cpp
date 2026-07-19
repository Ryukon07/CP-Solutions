#include <iostream>
#include <vector>

using ll = long long;

struct edge{
    ll id, u, v;
};

void solve(){
    ll n; std::cin >> n;
    std::vector<edge> edges(n - 1);
    std::vector<ll> deg(n + 1, 0);
    for(ll i = 0; i < n - 1; i++){
        std::cin >> edges[i].u >> edges[i].v;
        edges[i].id = i;
        deg[edges[i].u]++;
        deg[edges[i].v]++;
    }

    ll mid = -1;
    for(ll i = 1; i <= n; i++){
        if(deg[i] >= 3){
            mid = i;
            break;
        }
    }

    std::vector<ll> ans(n - 1, -1);
    ll curr = 0;

    if(mid != -1){
        for(ll i = 0; i < n - 1; i++){
            if(edges[i].u == mid || edges[i].v == mid){
                ans[edges[i].id] = curr++;
            }
        }
    }

    for(ll i = 0; i < n - 1; i++){
        if(ans[edges[i].id] == -1){
            ans[edges[i].id] = curr++;
        }
    }

    for(ll i = 0; i < n - 1; i++){
        std::cout << ans[i] << "\n";
    }

}

int main(){
    solve();
    return 0;
}