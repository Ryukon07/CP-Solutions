#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    if(a[n-2] > a[n-1]){
        std::cout << -1 << "\n";
        return;
    }else{
        if(a[n-1] >= 0){
            std::cout << n - 2 << "\n";
            for(ll i = 1; i < n - 1; i++){
                std::cout << i << " " << n - 1 << " " << n << "\n";
            }
        }else{
            std::is_sorted(a.begin(), a.end()) ? std::cout << 0 << "\n" : std::cout << -1 << "\n";
        }
    }

}

int main(){
    int t; std::cin >> t;
    while(t--){
        solve();
    }
}