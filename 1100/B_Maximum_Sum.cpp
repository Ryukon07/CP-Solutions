#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n, k; std::cin >> n >> k;
    std::vector<ll> a(n);

    ll ans = 0;

    for(ll i = 0; i < n; i++) std::cin >> a[i];
    std::sort(a.begin(), a.end());

    std::vector<ll> prefix(n);
    prefix[0] = a[0];
    for(ll i = 1; i < n; i++) prefix[i] = prefix[i - 1] + a[i];

    for(ll i = 0; i <= k; i++){
        ll j = k - i;
        ll l = 2 * i, r = n - 1 - j;

        ll sum = prefix[r] - (l == 0 ? 0 : prefix[l - 1]);
        ans = std::max(ans, sum); 
    }

    std::cout << ans << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}