#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<std::vector<ll>> mat(m, std::vector<ll>(n));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            std::cin >> mat[j][i];
        }
    }

    for(ll i = 0; i < m; i++){
        std::sort(mat[i].begin(), mat[i].end());
    }

    ll ans = 0;

    for(ll i = 0; i < m; i++){
        ll prefix = 0;
        for(ll j = 0; j < n; j++){
            ans += mat[i][j] * j - prefix;
            prefix += mat[i][j];
        }
    }

    std::cout << ans << "\n";

}

int main(){
    int t; std::cin >> t;
    while(t--){
        solve();
    }
}