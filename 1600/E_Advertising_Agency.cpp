#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using ll = long long;
const ll MOD = 1e9 + 7;

ll power(ll base, ll exp){
    ll res = 1;
    while(exp){
        if(exp % 2) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll a){
    return power(a, MOD - 2);
}

ll nCr(ll n, ll r){
    if(r > n) return 0;
    if(r == 0 || r == n) return 1;
    if(r > n - r) r = n - r;

    ll num = 1, den = 1;
    for(ll i = 0; i < r; i++){
        num = (num * (n - i)) % MOD;
        den = (den * (i + 1)) % MOD;
    }
    return (num * modInverse(den)) % MOD;

}

void solve(){
    ll n, k; std::cin >> n >> k;
    std::map<ll, ll> mp;
    std::vector<ll> a(n);

    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        mp[a[i]]++;
    }

    std::sort(a.begin(), a.end());

    std::map<ll, ll> freq;
    ll ans = 1;

    for(ll i = n - 1; i >= n - k; i--) freq[a[i]]++;

    for(auto [num, count] : freq) ans *= nCr(mp[num], count) % MOD;

    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;

}