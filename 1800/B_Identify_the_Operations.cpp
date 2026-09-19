#include <iostream>
#include <vector>

using ll = long long;
const ll MOD = 998244353;

void solve(){
    ll n, k; std::cin >> n >> k;
    std::vector<ll> a(n), b(k);
    std::vector<ll> pos(n + 1);
    
    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        pos[a[i]] = i;
    }

    std::vector<bool> inB(n + 1, false);
    for(ll i = 0; i < k; i++){
        std::cin >> b[i];
        inB[b[i]] = true;
    }

    ll total = 1;

    for(ll i = 0; i < k; i++){
        ll val = b[i];
        ll idx = pos[val];
        ll valid = 0;

        if(idx > 0 && !inB[a[idx - 1]]) valid++;
        if(idx < n - 1 && !inB[a[idx + 1]]) valid++;

        total = (total * valid) % MOD;
        inB[val] = false;
    }

    std::cout << total << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}