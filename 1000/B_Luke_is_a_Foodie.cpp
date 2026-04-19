#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, k; std::cin >> n >> k;
    std::vector<ll> a(n);
    std::vector<std::pair<ll, ll>> b(n);
    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        b[i] = {a[i] - k, a[i] + k};
    }

    ll ans = 0;
    ll l = b[0].first, r = b[0].second;
    for(ll i = 1; i < n; i++){
        l = std::max(l, b[i].first);
        r = std::min(r, b[i].second);
        if(l > r){
            ans++;
            l = b[i].first;
            r = b[i].second;
        }
    }
    std::cout << ans << "\n";
}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}