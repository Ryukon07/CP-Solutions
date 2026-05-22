#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n, c; std::cin >> n >> c;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        ll x; std::cin >> x;
        a[i] = x + i + 1;
    }
    std::sort(a.begin(), a.end());
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(a[i] <= c){
            ans++;
            c -= a[i];
        }
        else break;
    }
    std::cout << ans << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}