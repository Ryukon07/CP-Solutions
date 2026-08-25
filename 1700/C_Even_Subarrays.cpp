#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    ll ans = 1LL * n * (n + 1) / 2;

    ll MAX = 1;
    while(MAX <= n) MAX <<= 1;

    std::vector<ll> freq(MAX, 0);
    freq[0] = 1;

    ll curr = 0;

    for(ll i = 0; i < n; i++){
        curr ^= a[i];
        for(ll j = 0; j * j < MAX; j++){
            ll target = curr ^ (j * j);
            if(target < MAX) ans -= freq[target];
        }
        freq[curr]++;
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