#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using ll = long long;
const ll MOD = 1e9 + 7;

ll power(ll base, ll exp){
    ll res = 1;
    base %= MOD;
    while(exp > 0){
        if(exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n){
    return power(n, MOD - 2);
}

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<ll> a(n);
    std::map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        mp[a[i]]++;
    }

    std::vector<std::pair<ll, ll>> check;

    for(auto p: mp) check.push_back(p);

    ll x = check.size();
    if(x < m){
        std::cout << 0 << "\n";
        return;
    }

    ll ans = 0, curr = 1;
    for(ll i = 0; i < m; i++) curr = (curr * check[i].second) % MOD;

    if(check[m-1].first - check[0].first == m - 1) ans = (ans + curr) % MOD;

    for(ll i = m; i < x; i++){
        curr = (curr * check[i].second) % MOD;
        curr = (curr * modInverse(check[i - m].second)) % MOD;
        if(check[i].first - check[i - m + 1].first == m - 1) ans = (ans + curr) % MOD;
    }

    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;

}