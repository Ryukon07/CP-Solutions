#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;

void solve(){
    ll n, q; std::cin >> n >> q;
    std::vector<ll> a(n), x(q);
    for(ll i = 0; i < n; i++) std::cin >> a[i];
    for(ll i = 0; i < q; i++) std::cin >> x[i];

    ll min = 31;
    for(ll i = 0; i < q; i++){
        if(x[i] >= min) continue;
        ll value = std::pow(2, x[i]);
        for(ll j = 0; j < n; j++){
            if(a[j] % value == 0) a[j] += value/2;
        }
        min = x[i];
    }

    for(ll i = 0; i < n; i++) std::cout << a[i] << " ";
    std::cout << "\n";


}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}