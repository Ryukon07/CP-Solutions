#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using ll = long long;

void solve(){
    ll n, w; std::cin >> n >> w;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        ll tmp = log2(a[i]);
        mp[tmp]++;
    }

    ll total = 0, height = 0;
    while(total < n){
        ll curr = w;
        for(auto it = mp.rbegin(); it != mp.rend(); it++){
            while(it->second > 0 && curr >= (1LL << it->first)){
                curr -= (1LL << it->first);
                it->second--;
                total++;
            }
        }
        height++;
    }

    std::cout << height << std::endl;

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}