#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n, q; std::cin >> n >> q;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::vector<ll> freq(n + 2, 0);
    for(ll i = 0; i < q; i++){
        ll l, r; std::cin >> l >> r;
        freq[l]++;
        freq[r + 1]--;
    }

    std::vector<ll> prefix(n + 2, 0);
    for(ll i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + freq[i];
    }

    std::vector<ll> b = a;
    std::sort(b.begin(), b.end());
    std::sort(prefix.begin() + 1, prefix.begin() + n + 1);

    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        ans += b[i - 1] * prefix[i];
    }

    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}
