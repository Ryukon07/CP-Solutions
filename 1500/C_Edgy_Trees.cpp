#include <iostream>
#include <vector>

using ll = long long;
const ll MOD = 1e9 + 7;

ll find(std::vector<ll>& parent, ll a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent, parent[a]);
}

void unite(std::vector<ll>& parent, std::vector<ll>& size, ll a, ll b){
    a = find(parent, a);
    b = find(parent, b);
    if(a != b){
        if(size[a] < size[b]) std::swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}


void solve(){
    ll n, k; std::cin >> n >> k;

    std::vector<ll> parent(n), size(n, 1);
    for(ll i = 0; i < n; i++) parent[i] = i;

    ll ans = 0;
    for(ll i = 0; i < n - 1; i++){
        ll a, b, color; std::cin >> a >> b >> color;
        a--; b--;
        if(color == 0) unite(parent, size, a, b);
    }

    for(ll i = 0; i < n; i++){
        if(parent[i] == i){
            ll sz = size[i];
            ll bad = 1;
            for(ll j = 1; j <= k; j++){
                bad = (bad * sz) % MOD;
            }
            ans = (ans + bad) % MOD;
        }
    }

    ll total = 1;
    for(ll i = 1; i <= k; i++){
        total *= n % MOD;
        total %= MOD;
    }

    ans = (total - ans + MOD) % MOD;
    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}