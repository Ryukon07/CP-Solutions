#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::vector<ll> dp(n, 1);
    for(ll i = 1; i <= n; i++){
        for(ll j = 2 * i; j <= n; j += i){
            if(a[j - 1] > a[i - 1]) dp[j - 1] = std::max(dp[j - 1], dp[i - 1] + 1);
        }
    }

    std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}