#include <iostream>
#include <cmath>

using ll = long long;

void solve(){
    ll x, y, k; std::cin >> x >> y >> k;
    ll num = k * (y + 1) - x;
    ll den = x - 1;
    ll ans = (num + den - 1) / den;
    std::cout << ans + k + 1<< "\n";

}
int main(){

    ll t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}