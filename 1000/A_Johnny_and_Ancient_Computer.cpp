#include <iostream>
#include <cmath>

using ll = long long;

void solve(){
    ll a, b; std::cin >> a >> b;
    ll tempa = a, tempb = b;

    while(tempa % 2 == 0) tempa /= 2;
    while(tempb % 2 == 0) tempb /= 2;

    if(tempa != tempb) {
        std::cout << -1 << "\n";
    }else{
        a /= tempa;
        b /= tempb;

        ll ans = std::ceil((std::abs(log2(a) - log2(b))) / 3);
        std::cout << ans << "\n";
    }
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}