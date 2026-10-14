#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

struct DSU {
    std::vector<ll> parent;
    DSU(ll n) : parent(n + 1){
        for(ll i = 0; i <= n; i++) parent[i] = i;
    }

    ll find(ll x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(ll x, ll y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        parent[x] = y;
        return true;
    }
};

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i++) std::cin >> a[i];

    std::vector<std::pair<ll, ll>> ans;
    DSU dsu(n);

    for(ll i = n - 1; i >= 1; i--){
        ll u = -1, v = -1;
        std::vector<ll> b(i, 0);

        for(ll j = 1; j <= n; j++){
            ll rem = a[j] % i;
            ll root = dsu.find(j);

            if(b[rem] == 0) b[rem] = j;
            else{
                if(dsu.find(b[rem]) != root){
                    u = b[rem];
                    v = j;
                    break;
                }
            }
        }

        ans.push_back({u, v});
        dsu.unite(u, v);
    }

    std::reverse(ans.begin(), ans.end());

    std::cout << "YES\n";
    for(auto [u, v] : ans) std::cout << u << " "<< v << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}