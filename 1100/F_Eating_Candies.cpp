#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> w(n), pref(n), suff(n);
    for(ll i = 0; i < n; i++) std::cin >> w[i];
    pref[0] = w[0];
    for(ll i = 1; i < n; i++) pref[i] = pref[i - 1] + w[i];
    suff[n - 1] = w[n - 1];
    for(ll i = n - 2; i >= 0; i--) suff[i] = suff[i + 1] + w[i];

    ll ans = 0;

    ll i = 0, j = n - 1;

    while(i < j){
        if(pref[i] < suff[j]){
            i++;
        } else if(pref[i] > suff[j]){
            j--;
        } else {
            ans = std::max(ans, i + 1 + n - j);
            i++; j--;
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