#include <iostream>
#include <vector>

using ll = long long;

ll prefixXOR(ll n){
    if(n < 0) return 0;
    if(n % 4 == 0) return n;
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n + 1;
    return 0;
}

void solve(){
    ll l, r, i, k; std::cin >> l >> r >> i >> k;

    ll totalXOR = prefixXOR(r) ^ prefixXOR(l - 1);

    ll mod = 1LL << i;
    ll ymin = (l < k) ? 0 : (l - k + mod - 1) / mod;
    ll ymax = (r < k) ? -1 : (r - k) / mod;

    ll bad = 0;
    if(ymin <= ymax){
        ll cnt = ymax - ymin + 1;
        ll yXOR = prefixXOR(ymax) ^ prefixXOR(ymin - 1);
        bad = (yXOR << i) | ((cnt % 2 != 0) ? k : 0);
    }

    std::cout << (totalXOR ^ bad) << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}