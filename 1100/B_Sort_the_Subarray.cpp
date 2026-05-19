#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n), aDash(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];
    for(ll i = 0; i < n; i++) std::cin >> aDash[i];

    ll l = 0, r = n - 1;
    while(l < n && a[l] == aDash[l]) l++;
    while(r >= 0 && a[r] == aDash[r]) r--;

    while(l > 0 && aDash[l - 1] <= aDash[l]) l--;
    while(r < n - 1 && aDash[r] <= aDash[r + 1]) r++;

    std::cout << l + 1 << " " << r + 1 << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}