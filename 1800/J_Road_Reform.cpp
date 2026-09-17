#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

struct Edge{
    ll u, v, w;
};

ll find(std::vector<ll> &parent, ll x){
    if(parent[x] != x) parent[x] = find(parent, parent[x]);
    return parent[x];
}

void merge(std::vector<ll> &parent, std::vector<ll> &size, ll x, ll y){
    x = find(parent, x);
    y = find(parent, y);
    if(x == y) return;
    if(size[x] < size[y]) std::swap(x, y);
    parent[y] = x;
    size[x] += size[y];
}


void solve(){
    ll n, m, k; std::cin >> n >> m >> k;
    std::vector<Edge> edges(m);
    for(ll i = 0; i < m; ++i) std::cin >> edges[i].u >> edges[i].v >> edges[i].w;
    
    std::sort(edges.begin(), edges.end(), [k](const Edge &a, const Edge &b){
        ll costa = (a.w > k) ? (a.w - k) : 0;
        ll costb = (b.w > k) ? (b.w - k) : 0;
        return costa < costb;
    });


    std::vector<ll> parent(n + 1), size(n + 1, 1);
    for(ll i = 1; i <= n; ++i) parent[i] = i;

    ll cost = 0;
    bool check = false;

    for(const auto &e : edges){
        if(find(parent, e.u) != find(parent, e.v)){
            merge(parent, size, e.u, e.v);
            if(e.w > k) cost += (e.w - k);
            if(e.w >= k) check = true;
        }
    }

    if(check) std::cout << cost << "\n";
    else{
        ll min = 1e18;
        for(const auto &e : edges) min = std::min(min, std::abs(e.w - k));
        std::cout << min << "\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}