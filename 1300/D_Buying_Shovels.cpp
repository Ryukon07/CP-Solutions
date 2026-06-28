#include <iostream>

using ll = long long;

void solve(){
    ll n, k; std::cin >> n >> k;

    ll best = 1;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            ll d1 = i;
            ll d2 = n / i;

            if(d1 <= k) best = std::max(best, d1);
            if(d2 <= k) best = std::max(best, d2);
        }
    }
    std::cout << n / best << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}