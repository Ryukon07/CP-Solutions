#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    ll ans = 0, r = n - 1;
    while(r >= 0 && a[r] == a[n-1]) r--;
    if(r == -1){std::cout << 0 << "\n"; return;}
    while(r >= 0){
        r -= (n - 1 - r);
        ans++;
        while(r >= 0 && a[r] == a[n-1]) r--;
    }
    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}