#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<std::vector<ll>> mat(n, std::vector<ll>(m));
    for(ll i = 0; i < n; ++i) for(ll j = 0; j < m; ++j) std::cin >> mat[i][j];

    if((n + m - 1) % 2 != 0){
        std::cout << "NO\n";
        return;
    }

    std::vector<std::vector<ll>> minDP(n, std::vector<ll>(m)), maxDP(n, std::vector<ll>(m));

    for(ll i = 0; i < n; ++i) for(ll j = 0; j < m; ++j){
        if(i == 0 && j == 0) minDP[i][j] = maxDP[i][j] = mat[i][j];
        else if(i == 0) minDP[i][j] = minDP[i][j - 1] + mat[i][j], maxDP[i][j] = maxDP[i][j - 1] + mat[i][j];
        else if(j == 0) minDP[i][j] = minDP[i - 1][j] + mat[i][j], maxDP[i][j] = maxDP[i - 1][j] + mat[i][j];
        else{
            minDP[i][j] = std::min(minDP[i - 1][j], minDP[i][j - 1]) + mat[i][j];
            maxDP[i][j] = std::max(maxDP[i - 1][j], maxDP[i][j - 1]) + mat[i][j];
        }
    }

    if(minDP[n - 1][m - 1] <= 0 && maxDP[n - 1][m - 1] >= 0 && (n + m - 1) % 2 == 0) std::cout << "YES\n";
    else std::cout << "NO\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t; std::cin >> t;
    while(t--) solve();
    return 0;
}