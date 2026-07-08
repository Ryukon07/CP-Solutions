#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, x, y; std::cin >> n >> x >> y;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    ll S = 0;
    for(ll i = 0; i < n; i++) S ^= a[i] % 2;

    ll aliceParity = (x % 2) ^ S, bobParity = ((x + 3) % 2) ^ S;

    if((y % 2) == aliceParity) std::cout << "Alice\n";
    else std::cout << "Bob\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}