#include <iostream>
#include <vector>

using ll = long long;
std::vector<std::vector<ll>> divisors(100001);

void solve() {
    ll n, x;
    std::cin >> n >> x;

    std::vector<ll> a(n);
    for (ll i = 0; i < n; i++) std::cin >> a[i];

    ll ans = 1;
    std::vector<bool> checks(x + 1, false);
    checks[1] = true;

    for (ll i = 0; i < n; i++) {
        if (x % a[i] != 0) continue;

        if (checks[x / a[i]]) {
            ans++;

            for (ll d : divisors[x])
                checks[d] = false;

            checks[1] = true;
        }

        for (ll j = divisors[x].size(); j-- > 0;) {
            ll d = divisors[x][j];

            if (d % a[i] == 0 && checks[d / a[i]]) {
                checks[d] = true;
            }
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (ll i = 1; i <= 100000; i++)
        for (ll j = i; j <= 100000; j += i)
            divisors[j].push_back(i);

    ll t;
    std::cin >> t;
    while (t--) solve();
}
