#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n), b(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];
    for(ll i = 0; i < n; i++) std::cin >> b[i];

    std::map<ll, std::vector<ll>> mp;
    for(ll i = 0; i < n; i++) mp[a[i]].push_back(b[i]);

    for(auto &[key, vec]: mp) std::sort(vec.rbegin(), vec.rend());

    std::map<ll, std::vector<ll>> mpPrefixSum;

    for(auto &[key, vec]: mp){
        std::vector<ll> prefixSum(vec.size());
        prefixSum[0] = vec[0];
        for(ll i = 1; i < vec.size(); i++) prefixSum[i] = prefixSum[i - 1] + vec[i];
        mpPrefixSum[key] = prefixSum;
    }

    std::vector<ll> ans(n + 1, 0);
    for(auto &[key, vec]: mpPrefixSum){
        ll x = vec.size();
        for(ll k = 1; k <= x; k++){
            ll rem = x % k;
            ans[k] += vec[x - 1 - rem];
        }
    }

    for(ll i = 1; i <= n; i++) std::cout << ans[i] << " ";
    std::cout << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}