#include <iostream>
#include <vector>
#include <map>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        a[i] -= i;
    }

    std::map<ll, ll> freq;

    for(ll i = 0; i < n; i++){
        freq[a[i]]++;
    }

    ll ans = 0;
    for(auto [key, value] : freq){
        ans += (value * (value - 1)) / 2;
    }
    std::cout << ans << std::endl;
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}