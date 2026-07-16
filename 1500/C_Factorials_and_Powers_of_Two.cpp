#include <iostream>
#include <vector>
#include <climits>

using ll = long long;
std::vector<ll> factorials;
std::vector<std::vector<ll>> subsets;

void solve(){
    ll n; std::cin >> n;
    ll ans = LLONG_MAX;

    for(const auto& subset : subsets){
        ll sum = 0;
        for(ll num : subset) sum += num;
        if(sum <= n) {
            ll ones = __builtin_popcountll(n - sum);
            ans = std::min(ans, (ll)subset.size() + ones);
        }
    }
    std::cout << ans << std::endl;


}

int main(){
    ll t; std::cin >> t;

    for(ll i = 3; i <= 14; i++){
        ll fact = 1;
        for(ll j = 2; j <= i; j++) fact *= j;
        factorials.push_back(fact);
    }

    for(ll i = 0; i < (1 << factorials.size()); i++){
        std::vector<ll> subset;
        for(ll j = 0; j < factorials.size(); j++){
            if(i & (1 << j)) subset.push_back(factorials[j]);
        }
        subsets.push_back(subset);
    }

    while(t--) solve();
}