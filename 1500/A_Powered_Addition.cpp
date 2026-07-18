#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n); 
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    ll ans = 0;
    for(ll i = 0; i < n - 1;){
        if(a[i] > a[i + 1]){
            ll tmp = a[i];
            while(i < n - 1 && tmp > a[i + 1]){
                ll min = 64 - __builtin_clzll((unsigned long long)(tmp - a[i+1]));
                ans = std::max(ans, min);
                i++;
            }
        }
        else i++;
    }
    std::cout << ans << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}