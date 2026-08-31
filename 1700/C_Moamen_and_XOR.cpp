#include <iostream>

using ll = long long;

const ll MOD = 1e9 + 7;

ll power(ll base, ll exp){
    ll res = 1;
    base %= MOD;
    while(exp){
        if(exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

void solve(){
    ll n, k; std::cin >> n >> k;

    if(k == 0){
        std::cout << 1 << "\n";
        return;
    }

    if(n % 2){
        ll ans = (power(2, n - 1) + 1) % MOD;
        ans = power(ans, k);
        std::cout << ans << "\n";
    }else{
        ll ans = 0;
        ll same = (power(2, n - 1) - 1 + MOD) % MOD;
        ll b = power(2, n);
        for(ll i = k - 1; i >= 0; i--){
            ll curr = power(same, k - i - 1);
            ll rem = power(b, i);
            ll total = (curr * rem) % MOD;
            ans = (ans + total) % MOD;
        }
        ans = (ans + power(same, k)) % MOD;
        std::cout << ans << "\n";
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while(t--) solve();

}