#include <iostream>

using ll = long long;

void solve(){
    ll n; std::cin >> n;

    ll ans = (1 << 30) - 1;
    for(ll i = 0; i < n; i++){
        ll x; std::cin >> x;
        if( x != i) ans &= x;
    }
    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }

}