#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using ll = long long;

ll pairSum(std::vector<ll>& v){
    std::sort(v.begin(), v.end());
    ll total = 0, prefix = 0;
    for(ll i = 0; i < v.size(); ++i){
        total += (ll)(i) * v[i] - prefix;
        prefix += v[i];
    }
    return total;
}

void solve(){
    ll n, m; std::cin >> n >> m;
    std::map<ll, std::vector<ll>> rows, cols;

    for(ll i = 0; i < n; ++i){
        for(ll j = 0; j < m; ++j){
            ll x; std::cin >> x;
            rows[x].push_back(i);
            cols[x].push_back(j);
        }
    }

    ll ans = 0;
    for(auto& [_, v] : rows) ans += pairSum(v);
    for(auto& [_, v] : cols) ans += pairSum(v);

    std::cout << ans << "\n";

}

int main(){
    solve();
}