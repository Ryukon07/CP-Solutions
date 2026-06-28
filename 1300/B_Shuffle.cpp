#include <iostream>

using ll = long long;

void solve(){
    ll n, x, m; std::cin >> n >> x >> m;

    ll l = x, r = x;
    for(ll i = 0; i < m; i++){
        ll a, b; std::cin >> a >> b;
        if(b < l || a > r) continue;
        l = std::min(l, a);
        r = std::max(r, b);
    }
    std::cout << r - l + 1 << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}