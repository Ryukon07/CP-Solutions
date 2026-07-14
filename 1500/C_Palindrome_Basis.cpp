#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
std::vector<ll> palindromes, dp(40005, 0);
const ll MOD = 1e9 + 7;

void solve(){
    ll n; std::cin >> n;
    std::cout << dp[n] << "\n";
}

int main(){

    for(ll i = 1; i <= 40004; i++){
        std::string s = std::to_string(i);
        std::string rev = s;
        std::reverse(rev.begin(), rev.end());
        if(s == rev) palindromes.push_back(i);
    }

    dp[0] = 1;
    for(auto p : palindromes){
        for(ll i = p; i <= 40004; i++){
            dp[i] = (dp[i] + dp[i - p]) % MOD;
        }
    }

    ll t; std::cin >> t;
    while(t--) solve();
}