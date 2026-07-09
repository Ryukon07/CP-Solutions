#include <iostream>
#include <vector>
#include <map>

using ll = long long;

void solve(){
    ll a, b, n; std::cin >> a >> b >> n;
    std::vector<ll> boys(n), girls(n);
    for(ll i = 0; i < n; i++) std::cin >> boys[i];
    for(ll i = 0; i < n; i++) std::cin >> girls[i];

    std::vector<ll> boysCount(a + 1, 0), girlsCount(b + 1, 0);

    for(ll i = 0; i < n; i++){
        boysCount[boys[i]]++;
        girlsCount[girls[i]]++;
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ans += n - boysCount[boys[i]] - girlsCount[girls[i]] + 1;
    }
    std::cout << ans / 2 << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}