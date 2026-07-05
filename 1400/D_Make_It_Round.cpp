#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using ll = long long;

void solve(){
    ll n, k; std::cin >> n >> k;

    std::vector<ll> pow10(19, 1);
    for(ll i = 1; i < 19; i++){
        pow10[i] = pow10[i - 1] * 10;
    }
    
    ll ans = 0;
    for(ll i = 18; i >= 0; i--){
        ll pow = pow10[i];
        ll min = (pow) / (std::gcd(pow, n));
        if(min <= k){
            ll x = (k / min) * min;
            ans = x * n;
            break;
        }else{
            continue;
        }
    }

    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}