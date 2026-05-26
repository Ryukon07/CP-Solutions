#include <iostream>
#include <vector>
#include <numeric>

using ll = long long;

void solve(const std::vector<std::vector<ll>>& coprime){
    ll n; std::cin >> n;
    std::vector<ll> indices(1001, 0);
    for(int i = 0; i < n; i++) {ll x; std::cin >> x; indices[x] = i + 1;}

    ll ans = -1;

    for(int i = 1; i <= 1000; i++){
        if(indices[i] == 0) continue;
        for(int j : coprime[i]){
            if(indices[j] != 0){
                ans = std::max(ans, indices[i] + indices[j]);
            }
        }
    }

    std::cout << ans << "\n";

}

int main(){
    std::vector<std::vector<ll>> coprime(1001);
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            if(std::gcd(i, j) == 1){
                coprime[i].push_back(j);
            }
        }
    }

    ll t; std::cin >> t;
    while(t--){
        solve(coprime);
    }
}