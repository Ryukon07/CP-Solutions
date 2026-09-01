#include <iostream>
#include <vector>

using ll = long long;
const ll INF = 1e18;

ll score(char c1, char c2, char c3){
    ll x = (c1 == 'A') + (c2 == 'A') + (c3 == 'A');
    return (x >= 2) ? 1 : 0;
}

ll count(std::vector<std::string> &a, ll state, ll column, ll n, std::vector<std::vector<ll>> &dp){
    if(column > n) return -INF;
    if(column == n) return (state == 0) ? 0 : -INF;

    if(dp[state][column] != -INF) return dp[state][column];

    ll max = -INF;

    if(state == 0){
        // Top right L-shape
        if(column + 1 < n){
            ll score1 = score(a[0][column], a[1][column], a[0][column + 1]);
            ll res = score1 + count(a, 1, column + 1, n, dp);
            max = std::max(max, res);
        }

        // Bottom right L-shape
        if(column + 1 < n){
            ll score1 = score(a[0][column], a[1][column], a[1][column + 1]);
            ll res = score1 + count(a, 2, column + 1, n, dp);
            max = std::max(max, res);
        }

        // Horizontal line
        if(column + 3 <= n){
            ll score1 = score(a[0][column], a[0][column + 1], a[0][column + 2]) + score(a[1][column], a[1][column + 1], a[1][column + 2]);
            ll res = score1 + count(a, 0, column + 3, n, dp);
            max = std::max(max, res);
        }
        
    }else if(state == 1){

        // Bottom left L-shape
        if(column + 1 < n){
            ll score1 = score(a[0][column + 1], a[1][column], a[1][column + 1]);
            ll res = score1 + count(a, 0, column + 2, n, dp);
            max = std::max(max, res);
        }

        // Horizontal line
        if(column + 3 < n){
            ll score1 = score(a[0][column + 1], a[0][column + 2], a[0][column + 3]) + score(a[1][column], a[1][column + 1], a[1][column + 2]);
            ll res = score1 + count(a, 1, column + 3, n, dp);
            max = std::max(max, res);
        }

    }else if(state == 2){

        // Top left L-shape
        if(column + 1 < n){
            ll score1 = score(a[0][column], a[0][column + 1], a[1][column + 1]);
            ll res = score1 + count(a, 0, column + 2, n, dp);
            max = std::max(max, res);
        }

        // Horizontal line
        if(column + 3 < n){
            ll score1 = score(a[0][column], a[0][column + 1], a[0][column + 2]) + score(a[1][column + 1], a[1][column + 2], a[1][column + 3]);
            ll res = score1 + count(a, 2, column + 3, n, dp);
            max = std::max(max, res);
        }
    }

    return dp[state][column] = max;

}

void solve(){
    ll n; std::cin >> n;
    std::vector<std::string> a(2);
    std::cin >> a[0] >> a[1];

    std::vector<std::vector<ll>> dp(3, std::vector<ll>(n + 1, -INF));

    std::cout << count(a, 0, 0, n, dp) << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}