#include <iostream>

using ll = long long;
const ll MOD = 1e9 + 7;

ll power(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve(){
    ll n, m, k; std::cin >> n >> m >> k;
    ll sum = 0;
    for(ll i = 0; i < m; i++){
        ll a, b, f; std::cin >> a >> b >> f;
        sum = (sum + f) % MOD;
    }

    ll d = (n * (n - 1) / 2);
    ll inv = power(d % MOD, MOD - 2);
    
    ll first = k * sum % MOD * inv % MOD;

    ll second = m * (k * (k - 1) / 2) % MOD;
    second = second * inv % MOD * inv % MOD;

    std::cout << (first + second) % MOD << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}