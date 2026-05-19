#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
const ll MOD = 1e9 + 7;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n + 1), b(n + 1);
    for(ll i = 1; i <= n; i++) std::cin >> a[i]; 
    for(ll i = 1; i <= n; i++) std::cin >> b[i];

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    ll ans = 1;

    ll j = 1;
    for(ll i = 1; i <= n; i++){
        while(j <= n && a[i] > b[j]) j++;
        if(j - i == 0){
            ans = 0;
            break;
        }else{
            ans = ((ans * (j - i)) % MOD) % MOD;
        }
    }

    std::cout << ans << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}