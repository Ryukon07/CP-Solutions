#include <iostream>
#include <map>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::map<ll, ll> fir, sec;
    std::vector<std::pair<ll, ll>> arr(n);

    for(ll i = 0; i < n; i++){
        std::cin >> arr[i].first >> arr[i].second;
        fir[arr[i].first]++;
        sec[arr[i].second]++;
    }

    ll ans = n * (n - 1) * (n - 2) / 6;

    for(auto [key, value] : arr){
        ans -= (fir[key] - 1) * (sec[value] - 1);
    }

    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;

}