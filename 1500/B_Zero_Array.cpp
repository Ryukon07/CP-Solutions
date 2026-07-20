#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    
    ll total = 0, max = 0;
    for(ll i = 0; i < n; i++){
        ll x; std::cin >> x;
        total += x;
        if(x > max) max = x;
    }

    if(total % 2 == 0 && max <= total / 2) std::cout << "YES\n";
    else std::cout << "NO\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}