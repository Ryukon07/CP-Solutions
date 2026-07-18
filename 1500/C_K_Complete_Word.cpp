#include <iostream>
#include <vector>
#include <string>
#include <map>

using ll = long long;

void solve(){
    ll n, k; std::cin >> n >> k;
    std::string s; std::cin >> s;

    ll ans = 0;
    for(ll i = 0; i < (k + 1)/2; i++){
        std::map<char, ll> freq;
        ll total = 0;

        for(ll j = i; j < n; j += k){
            freq[s[j]]++;
            total++;
        }

        if (k - 1 - i != i) {
        for (ll j = k - 1 - i; j < n; j += k) {
                freq[s[j]]++;
                total++;
            }
        }

        ll max_freq = 0;
        for(auto& p : freq) max_freq = std::max(max_freq, p.second);

        ans += total - max_freq;
    }

    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}