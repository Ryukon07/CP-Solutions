#include <iostream>
#include <vector>

using ll = long long;
const ll MOD = 998244353;

const std::vector<std::vector<ll>> p = {
    {0, 0, 0},
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 0}
};

ll dp[200005][3][4];

ll check(ll index, ll step, ll count, const std::vector<ll>& pattern, const std::vector<ll>& a){
    if(index == a.size()) return (count >= 3) ? 1 : 0;

    if(dp[index][step][count] != -1) return dp[index][step][count];

    ll ways = check(index + 1, step, count, pattern, a);

    ll curr = a[index] % 2;
    if(curr == pattern[step]){
        ll next = (step + 1) % 3;
        ll countNext = std::min(3LL, count + 1);
        ways += check(index + 1, next, countNext, pattern, a);
    }
    ways %= MOD;

    return dp[index][step][count] = ways;

}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);

    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        if(a[i] % 2) a[i] = 1;
        else a[i] = 0;
    }

    ll ans = 0;
    for(ll pattern = 0; pattern < 4; pattern++){
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < 3; j++){
                for(ll k = 0; k < 4; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        ans += check(0, 0, 0, p[pattern], a);
    }

    std::cout << ans % MOD << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}