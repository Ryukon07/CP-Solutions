#include <iostream>
#include <vector>
#include <numeric>

using ll = long long;

void solve(){
    ll n, m, k; std::cin >> n >> m >> k;
    std::vector<std::vector<ll>> a(n, std::vector<ll>(m));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            std::cin >> a[i][j];
        }
    }

    ll total0 = 0, total1 = 0;
    std::vector<std::vector<ll>> prefix(n + 1, std::vector<ll>(m + 1, 0));

    for(ll i = 0; i < n; i++){
        std::string s; std::cin >> s;
        for(ll j = 0; j < m; j++){
            ll val = (s[j] == '0') ? 1: -1;
            if(s[j] == '0') total0 += a[i][j];
            else total1 += a[i][j];
            prefix[i + 1][j + 1] = prefix[i + 1][j] + prefix[i][j + 1] - prefix[i][j] + val;

        }
    }

    ll g = 0;
    for(ll i = 1; i + k - 1 <= n; i++){
        for(ll j = 1; j + k - 1 <= m; j++){
            ll sum = prefix[i + k - 1][j + k - 1] - prefix[i + k - 1][j - 1] - prefix[i - 1][j + k - 1] + prefix[i - 1][j - 1];
            g = std::gcd(g, std::abs(sum));
        }
    }

    ll target = std::abs(total0 - total1);

    if(target == 0) std::cout << "YES\n";
    else if(g != 0 && target % g == 0) std::cout << "YES\n";
    else std::cout << "NO\n";


}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}