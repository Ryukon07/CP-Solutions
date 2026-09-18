#include <iostream>
#include <vector>

using ll = long long;
const ll MOD = 1e9 + 7;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::vector<ll> cnt(61, 0);

    for(ll i = 0; i < n; i++) for(ll j = 0; j < 61; j++) if(a[i] & (1LL << j)) cnt[j]++;

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll num = a[i];
        ll sumAnd = 0, sumOr = 0;
        ll p = 1;

        for(ll j = 0; j < 61; j++){
            ll count = cnt[j] % MOD;
            if(num & (1LL << j)) {
                sumAnd = (sumAnd + count * p) % MOD;
                sumOr = (sumOr + (n % MOD) * p) % MOD;
            }else sumOr = (sumOr + count * p) % MOD;
            p = (p * 2) % MOD;
        }

        ans = (ans + (sumAnd * sumOr) % MOD) % MOD;
    }

    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}