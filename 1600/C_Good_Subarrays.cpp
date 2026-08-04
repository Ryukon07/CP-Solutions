#include <iostream>
#include <vector>
#include <map>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::string s; std::cin >> s;

    std::vector<ll> b(n);

    for(ll i = 0; i < n; i++){
        b[i] = s[i] - '0';
        b[i]--;
    }

    std::vector<ll> prefix(n + 1, 0);
    for(ll i = 0; i < n; i++) prefix[i + 1] = prefix[i] + b[i];


    std::map<ll, ll> mp;
    for(ll i = 0; i <= n; i++) mp[prefix[i]]++;

    ll ans = 0;
    for(auto [key, value] : mp) ans += (value * (value - 1)) / 2;

    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}