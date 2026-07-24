#include <iostream>
#include <vector>

using ll = long long;

ll mod = 998244353;

ll nCr(ll n, ll r){
    if(r > n) return 0;
    if(r == 0 || r == n) return 1;

    std::vector<ll> fact(n + 1, 1);
    for(ll i = 2; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;

    ll numerator = fact[n];
    ll denominator = (fact[r] * fact[n - r]) % mod;

    ll inverseDenominator = 1;
    ll exponent = mod - 2;
    while(exponent > 0){
        if(exponent % 2 == 1) inverseDenominator = (inverseDenominator * denominator) % mod;
        denominator = (denominator * denominator) % mod;
        exponent /= 2;
    }

    return (numerator * inverseDenominator) % mod;
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    ll ans = 1;
    for(ll i = 0; i < n; i += 3){
        ll x = a[i], y = a[i + 1], z = a[i + 2];
        if(x == y && y == z) ans = (ans * 3) % mod;
        else if(x == y || y == z || x == z){
            if(x == y && x < z) ans = (ans * 2) % mod;
            if(y == z && y < x) ans = (ans * 2) % mod;
            if(x == z && x < y) ans = (ans * 2) % mod;
            ans = (ans * 1) % mod;
        }
        else ans = (ans * 1) % mod;
    }

    ans = (ans * nCr(n/3, n/6)) % mod;

    std::cout << ans << "\n";

}

int main(){

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}