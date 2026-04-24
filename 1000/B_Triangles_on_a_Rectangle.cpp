#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll w, h; std::cin >> w >> h;
    ll ans = 0;

    for(ll i = 0; i < 2; i++){
        ll x; std::cin >> x;
        std::vector<ll> temp(x);
        for(ll j = 0; j < x; j++) std::cin >> temp[j];

        ll length = temp.back() - temp[0];
        ans = std::max(ans, length * h);

    }

    for(ll i = 0; i < 2; i++){
        ll x; std::cin >> x;
        std::vector<ll> temp(x);
        for(ll j = 0; j < x; j++) std::cin >> temp[j];

        ll length = temp.back() - temp[0];
        ans = std::max(ans, length * w);
    }

    std::cout << ans << std::endl;

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}