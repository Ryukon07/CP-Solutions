#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::vector<std::vector<ll>> pref(n + 1, std::vector<ll>(30, 0));
    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j < 30; j++){
            if((a[i-1] >> j) & 1){
                pref[i][j] = pref[i - 1][j] + 1;
            } else {
                pref[i][j] = pref[i - 1][j];
            }
        }
    }

    ll q; std::cin >> q;
    for(ll i = 0; i < q; i++){
        ll l, k; std::cin >> l >> k;
        
        ll low = l, high = n, ans = -1;
        while(low <= high){
            ll mid = low + (high - low) / 2;
            ll cur = 0;
            ll count = mid - l + 1;

            for(ll j = 0; j < 30; j++){
                ll set = pref[mid][j] - pref[l - 1][j];
                if(set == count){
                    cur += (1LL << j);
                }
            }
            if(cur >= k){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        std::cout << ans << " ";
    }

    std::cout << std::endl;
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}