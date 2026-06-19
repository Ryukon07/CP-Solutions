#include <iostream>
#include <vector>
#include <map>

using ll = long long;

void solve(){

    ll n, x, y;
    std::cin >> n >> x >> y;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::map<std::pair<ll, ll>, ll> freq;

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll rx = a[i] % x;
        ll ry = a[i] % y;

        ans += freq[{(x - rx) % x, ry}];
        freq[{rx, ry}]++;
    }

    std::cout << ans << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}