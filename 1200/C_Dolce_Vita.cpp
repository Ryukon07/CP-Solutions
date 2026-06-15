#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n, x; std::cin >> n >> x;
    std::vector<ll> a(n), pref(n);
    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    pref[0] = a[0];
    for(ll i = 1; i < n; i++){
        pref[i] = pref[i - 1] + a[i];
    }

    ll ans = 0;
    for(ll k = 0; k < n; k++){
        if(pref[k] > x) break;
        ll days = (x - pref[k]) / (k + 1);
        ans += (days + 1);
    }

    std::cout << ans << "\n";
}

int main(){
    int t; std::cin >> t;
    while(t--){
        solve();
    }
}