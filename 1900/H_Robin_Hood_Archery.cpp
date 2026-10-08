#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>

using ll = long long;

void solve(){
    ll n, q; std::cin >> n >> q;
    std::vector<ll> a(n);
    std::unordered_map<ll, uint64_t> sumit;
    std::mt19937_64 rng(1337);

    for(ll i = 0; i < n; ++i){
        std::cin >> a[i];
        if(sumit.find(a[i]) == sumit.end()) sumit[a[i]] = rng();
    }

    std::vector<uint64_t> prefixXOR(n + 1, 0);
    for(ll i = 1; i <= n; ++i)  prefixXOR[i] = prefixXOR[i - 1] ^ sumit[a[i - 1]];

    while(q--){
        ll l, r; std::cin >> l >> r;
        ll ans = prefixXOR[r] ^ prefixXOR[l - 1];
        if(ans == 0) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}