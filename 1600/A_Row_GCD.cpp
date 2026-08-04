#include <iostream>
#include <vector>
#include <numeric>

using ll = long long;

void solve(){
    ll a, b; std::cin >> a >> b;

    std::vector<ll> arr(a);
    for(ll i = 0; i < a; i++) std::cin >> arr[i];
    
    ll g = 0;
    for(ll i = 1; i < a; i++) g = std::gcd(g, std::abs(arr[i] - arr[0]));

    for(ll i = 0; i < b; i++){
        ll x; std::cin >> x;
        std::cout << std::gcd(arr[0] + x, g) << " ";
    }

    std::cout << "\n";


}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();

    return 0;

}