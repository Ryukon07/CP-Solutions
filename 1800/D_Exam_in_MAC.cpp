#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, c; std::cin >> n >> c;
    std::vector<ll> a(n);
    ll evenCount = 0, oddCount = 0, total = (c + 1) * (c + 2) / 2;
    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        if(a[i] % 2 == 0) evenCount++;
        else oddCount++;

        total -= ((a[i] / 2) + 1);
        total -= (c - a[i] + 1);
    }

    std::cout << total + (evenCount) * (evenCount + 1) / 2 + (oddCount) * (oddCount + 1) / 2 << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
}