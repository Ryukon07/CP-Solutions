#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;

std::vector<ll> dp(2050000, 0);

void solve(){
    ll n; std::cin >> n;

    std::cout << dp[n] << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    dp[1] = 1;

    ll cnt = 2;
    for(ll i = 2; i <= 2023; i++){
        for(ll j = 1; j <= i; j++){
            ll left = 0, right = 0, overlap = 0;
            if(j > 1) left = dp[cnt - i];
            if(j < i) right = dp[cnt - i + 1];

            if(j > 1 && j < i) overlap = dp[cnt - 2 * i + 2];

            dp[cnt] = (cnt * cnt) + left + right - overlap;
            cnt++;

        }
    }

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;

}