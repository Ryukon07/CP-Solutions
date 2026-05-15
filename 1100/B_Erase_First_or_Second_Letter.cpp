#include <iostream>
#include <string>
#include <vector>
#include <map>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::string s; std::cin >> s;

    std::map<char, ll> freq;
    std::vector<ll> distinct(n, 0);
    ll count = 0;
    for(ll i = 0; i < n; i++){
        freq[s[i]]++;
        if(freq[s[i]] == 1) count++;
        distinct[i] = count;
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++) ans += distinct[i];

    std::cout << ans << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
        }
}