#include <iostream>
#include <vector>
#include <cstring>

using ll = long long;
const ll INF = 1e18;

const ll rx[4] = {0, 1, 0, -1};
const ll ry[4] = {1, 0, -1, 0};

ll dp[505][505][11];

ll recur(std::vector<std::vector<ll>>& horizontal, std::vector<std::vector<ll>>& vertical, ll n, ll m, ll rem, ll k, ll i, ll j){
    if(rem == 0) return 0;

    if(dp[i][j][rem] != -1) return dp[i][j][rem];
    
    ll ans = INF;

    for(ll d = 0; d < 4; d++){
        ll x = i + rx[d], y = j + ry[d];
        if(x < 0 || x >= n || y < 0 || y >= m) continue;

        ll weight = 0;
        if(i == x) weight = horizontal[i][std::min(j, y)];
        else weight = vertical[std::min(i, x)][j];

        ll curr = weight + recur(horizontal, vertical, n, m, rem - 1, k, x, y);
        ans = std::min(ans, curr);

    }

    return dp[i][j][rem] = ans;

}

void solve(){
    ll n, m, k; std::cin >> n >> m >> k;
    
    std::vector<std::vector<ll>> horizontal(n, std::vector<ll>(m - 1)), vertical(n - 1, std::vector<ll>(m));

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m - 1; j++){
            std::cin >> horizontal[i][j];
        }
    }

    for(ll i = 0; i < n - 1; i++){
        for(ll j = 0; j < m; j++){
            std::cin >> vertical[i][j];
        }
    }

    if(k % 2){
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                std::cout << -1 << " ";
            }
            std::cout << "\n";
        }
        return;
    }

    memset(dp, -1, sizeof(dp));

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            ll ans = recur(horizontal, vertical, n, m, k / 2, k, i, j);
            std::cout << ans * 2 << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}