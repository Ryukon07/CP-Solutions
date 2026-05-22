#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    ll sum = 0, absMin = 1e9, totalNegatives = 0;
    for(ll i = 0; i < n; i++){
        ll x; std::cin >> x;
        sum += std::abs(x);
        absMin = std::min(absMin, std::abs(x));
        if(x < 0) totalNegatives++;
    }

    if(totalNegatives % 2 == 0) std::cout << sum << "\n";
    else std::cout << sum - 2 * absMin << "\n";
}

int main(){

    ll t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}