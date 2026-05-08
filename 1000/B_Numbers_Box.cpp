#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, m; std::cin >> n >> m;

    ll sum = 0, minValue = 1e9, negatives = 0;

    std::vector<std::vector<ll>> a(n, std::vector<ll>(m));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            std::cin >> a[i][j];
            sum += std::abs(a[i][j]);
            minValue = std::min(minValue, std::abs(a[i][j]));
            if(a[i][j] < 0){
                negatives++;
            }
        }
    }

    if(negatives % 2 == 0){
        std::cout << sum << std::endl;
    } else {
        std::cout << sum - 2 * minValue << std::endl;
    }

}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}