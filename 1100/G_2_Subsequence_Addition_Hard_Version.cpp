#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> c(n);

    for(ll i = 0; i < n; i++) std::cin >> c[i];

    std::sort(c.begin(), c.end());

    if(c[0] != 1){
        std::cout << "NO\n";
        return;
    }

    ll sum = 1;
    for(ll i = 1; i < n; i++){
        if(c[i] > sum){
            std::cout << "NO\n";
            return;
        }
        sum += c[i];
    }

    std::cout << "YES\n";
    
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}