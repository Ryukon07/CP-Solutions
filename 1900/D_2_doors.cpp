#include <iostream>
#include <vector>

using ll = long long;
const ll MAX = (1 << 30) - 1;

void solve(){
    ll n, q; std::cin >> n >> q;

    std::vector<ll> a(n + 1, MAX);
    std::vector<std::vector<std::pair<ll, ll>>> adj(n + 1);

    for(ll i = 0; i < q; i++){
        ll x, y, z; std::cin >> x >> y >> z;
        adj[x].push_back({y, z});
        if(x != y) adj[y].push_back({x, z});

        a[x] &= z;
        a[y] &= z;
    }

    for(ll i = 1; i <= n; i++){
        ll need = 0;
        for(auto [j, z]: adj[i]){
            if(i == j) need |= z;
            else need |= (z & ~a[j]);
        }
        a[i] = need;
    }

    for(ll i = 1; i <= n; i++) std::cout << a[i] << " ";
    std::cout << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}