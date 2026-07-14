#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long; 

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n + 1), b(n + 1);

    for(ll i = 1; i <= n; i++) std::cin >> a[i];
    for(ll i = 1; i <= n; i++) std::cin >> b[i];

    std::vector<ll> prefb(n + 1, 0);
    for(ll i = 1; i <= n; i++) prefb[i] = prefb[i - 1] + b[i];

    std::vector<ll> cnt(n + 2, 0), rem(n + 2, 0);
    for(ll i = 1; i <= n; i++){
        ll tmp = a[i] + prefb[i - 1];

        ll idx = std::upper_bound(prefb.begin(), prefb.end(), tmp) - prefb.begin();

        if(idx <= n){
            cnt[i]++;
            cnt[idx]--;
            rem[idx] += tmp - prefb[idx - 1];
        } else {
            cnt[i]++;
        }
    }

    for(ll i = 1; i <= n; i++) cnt[i] += cnt[i - 1];

    for(ll i = 1; i <= n; i++) std::cout << cnt[i] * b[i] + rem[i] << " ";
    std::cout << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}