#include <iostream>
#include <vector>

using ll = long long;

std::string comb[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};

void solve(){
    ll n, m; std::cin >> n >> m;
    std::string s; std::cin >> s;

    std::vector<std::vector<ll>> dp(6, std::vector<ll>(n, 0));

    for(ll i = 0; i < 6; i++){
        for(ll j = 0; j < n; j++){
            if(s[j] != comb[i][j % 3]) dp[i][j]++;
            if(j > 0) dp[i][j] += dp[i][j-1];
        }
    }

    while(m--){
        ll l, r; std::cin >> l >> r; l--; r--;
        ll ans = n;
        for(ll i = 0; i < 6; i++){
            ll temp = dp[i][r];
            if(l > 0) temp -= dp[i][l-1];
            ans = std::min(ans, temp);
        }
        std::cout << ans << "\n";
    }


}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}