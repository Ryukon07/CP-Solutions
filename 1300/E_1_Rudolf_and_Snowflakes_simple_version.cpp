#include <iostream>
#include <cmath>

using ll = long long;

void solve(){
    ll n; std::cin >> n;

    for(ll k = 2; k <= 1000; k++){
        ll sum = 1;
        ll power = k;
        for(ll i = 1; i <= 20; i++){
            sum += power;
            power *= k;
            if(sum > n) break;
            if(i >= 2 && sum == n){
                std::cout << "YES" << "\n";
                return;
            }
        }
    }
    std::cout << "NO" << "\n";
}

int main(){

    ll t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}