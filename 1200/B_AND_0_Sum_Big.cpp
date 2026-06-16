#include <iostream>

using ll = long long;

const ll MOD = 1e9 + 7;

void solve(){
    ll n, k; std::cin >> n >> k;

    ll ans = 1;

    for(ll i = 0; i < k; i++){
        ans = (ans * n) % MOD;
    }
    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}