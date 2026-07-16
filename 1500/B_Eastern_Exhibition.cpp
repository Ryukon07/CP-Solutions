#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> x(n), y(n);
    for(ll i = 0; i < n; i++) std::cin >> x[i] >> y[i];

    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());

    ll totalX = x[n/2] - x[(n-1)/2] + 1;
    ll totalY = y[n/2] - y[(n-1)/2] + 1;

    std::cout << totalX * totalY << std::endl;

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}