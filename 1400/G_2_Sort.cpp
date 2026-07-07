#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, k; std::cin >> n >> k;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; ++i) std::cin >> a[i];

    ll ans = 0;
    ll curr = 0;
    for(ll i = 0; i < n - 1; i++){
        if(a[i] < 2 * a[i + 1]) curr++;
        else curr = 0;
        if(curr >= k) ans++;
    }

    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}