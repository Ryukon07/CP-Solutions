#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    ll total = 0;
    for(ll i = 0; i < n; i++) total ^= a[i];

    if(total == 0) {
        std::cout << "YES" << std::endl;
        return;
    }

    ll cnt = 0, real = 0;
    for(ll i = 0; i < n; i++){
        real ^= a[i];
        if(real == total) {
            cnt++;
            real = 0;
        }
    }

    if(cnt >= 3 && real == 0) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}