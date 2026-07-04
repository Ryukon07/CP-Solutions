#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<ll> a(n), b(n);
    a[0] = m;
    for(ll i = 1; i < n; i++) std::cin >> a[i];
    for(ll i = 0; i < n; i++) std::cin >> b[i];

    std::sort(b.begin(), b.end());
    std::sort(a.begin(), a.end());

    ll j = 0, match = 0;
    for(ll i = 0; i < n; i++){
        if(j < n && a[j] < b[i]){
            match++;
            j++;
        }
    }

    std::cout << n - match << std::endl;

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}