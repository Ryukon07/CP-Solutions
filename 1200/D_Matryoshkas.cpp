#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    std::map<ll, ll> freq;
    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        freq[a[i]]++;
    }

    ll ans = 0;
    for(auto& p : freq){
        ll x = p.first;
        ans += std::max(0LL, freq[x] - freq[x - 1]);
    }
    std::cout << ans << "\n"; 
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}