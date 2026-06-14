#include <iostream>
#include <vector>
#include <numeric>

using ll = long long;

void solve(){
    ll n, s; std::cin >> n >> s;
    std::vector<ll> a(n);

    ll total = 0;
    for(ll i = 0; i < n; i++) {
        std::cin >> a[i];
        total += a[i];
    }

    if(s > total) {std::cout << -1 << "\n"; return;}

    ll l = 0, sum = 0, len = 0;
    for(ll r = 0; r < n; r++){
        sum += a[r];
        while(sum > s) sum -= a[l++];
        len = std::max(len, r - l + 1);
    }

    std::cout << n - len << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}