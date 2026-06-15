#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<std::pair<ll, ll>> a(n);
    for(ll i = 0; i < n; i++){
        std::cin >> a[i].first;
        a[i].second = i + 1;
    }

    std::sort(a.begin(), a.end());

    ll ans = 0;

    for(ll i = 0; i < n; i++){
        for(ll j = i + 1; j < n; j++){
            if(a[i].first * a[j].first > 2 * n) break;
            if(a[i].first * a[j].first == a[i].second + a[j].second){
                ans++;
            }
        }
    }
    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}