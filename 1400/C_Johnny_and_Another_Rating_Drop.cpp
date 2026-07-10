#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    ll ones = __builtin_popcountll(n);

    std::cout << 2 * n - ones << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}