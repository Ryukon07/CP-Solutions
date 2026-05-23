#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, l, r; std::cin >> n >> l >> r;
    std::vector<ll> ans;

    for(ll i = 1; i <= n; i++){
        ll temp = (l + i - 1) / i * i;
        ans.push_back(temp);

        if(temp > r){
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
    for(ll x : ans){
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}