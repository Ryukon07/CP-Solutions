#include <iostream>
#include <vector>

using ll = long long;

ll parent[500005], size[500005];

ll find(ll x){
    while(parent[x] != x){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void unite(ll x, ll y){
    ll rootX = find(x);
    ll rootY = find(y);
    if(rootX == rootY) return;
    if(size[rootX] < size[rootY]) std::swap(rootX, rootY);
    parent[rootY] = rootX;
    size[rootX] += size[rootY];
}

void solve(){
    ll n, m; std::cin >> n >> m;

    for(ll i = 1; i <= n; i++){
        parent[i] = i;
        size[i] = 1;
    }

    for(ll i = 0; i < m; i++){
        ll k; std::cin >> k;
        ll first = -1;
        for(ll j = 0; j < k; j++){
            ll x; std::cin >> x;
            if(j == 0) first = x;
            else unite(first, x);
        }
    }

    for(ll i = 1; i <= n; i++){
        std::cout << size[find(i)] << " ";
    }
    std::cout << "\n";

}

int main(){
    solve();
}