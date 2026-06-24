#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::vector<std::pair<ll, ll>> name;
    for(ll i = 0; i < n; i++){
        if(a[i] < i + 1){
            name.push_back({a[i], i + 1});
        }
    }

    std::sort(name.begin(), name.end());

    ll ans = 0;

    for(ll i = 0; i < name.size(); i++){
        ll x = name[i].first;
        ll y = name[i].second;

        ll idx = std::upper_bound(name.begin(), name.end(),y, [](ll value, const std::pair<ll, ll>& p) {
            return value < p.first;
        }) - name.begin();
        ll len = name.size() - idx;
        ans += len;
    }

    std::cout << ans << "\n";

}

int main(){

    ll t; std::cin >> t;
    while(t--) solve()
;
    return 0;
}