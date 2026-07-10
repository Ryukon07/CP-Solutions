#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::map<ll, ll> freq;
    for(ll i = 0; i < n; i++){
        ll x; std::cin >> x;
        freq[x]++;
    }

    std::vector<std::pair<ll, ll>> freq_vec(freq.begin(), freq.end());

    std::sort(freq_vec.rbegin(), freq_vec.rend(), [](const auto &a, const auto &b){
        return a.second > b.second;
    });

    std::set<ll> distinct;

    for(auto [key, value] : freq_vec){
        if(distinct.find(value) == distinct.end()){
            distinct.insert(value);
        } else {
            while(value > 0 && distinct.find(value) != distinct.end()){
                value--;
            }
            if(value > 0){
                distinct.insert(value);
            }
        }
    }
    
    ll ans = 0;
    for(auto x : distinct) ans += x;

    std::cout << ans << "\n";

}

int main(){
    ll q; std::cin >> q;
    while(q--) solve();
}