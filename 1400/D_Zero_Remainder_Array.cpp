#include <iostream>
#include <vector>
#include <unordered_map>

using ll = long long;

void solve(){
    ll n, k; std::cin >> n >> k;
    std::unordered_map<ll, ll> needs;
    for(ll i = 0; i < n; i++){
        ll x; std::cin >> x;
        ll rem = x % k;
        if(rem != 0) needs[k - rem]++;
    }

    ll ans = 0;
    for(auto &[key, value]: needs){
        ll moves = (value - 1) * k + key;
        ans = std::max(ans, moves + 1);
    }
    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}