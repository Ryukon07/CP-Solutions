#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using ll = long long;

ll power(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::map<ll, std::vector<ll>> mp;

    for(ll i = 0; i < n; i++){
        ll x = a[i];
        for(ll j = 2; j * j <= x; j++){
            if(x % j == 0){
                ll cnt = 0;
                while(x % j == 0){
                    x /= j;
                    cnt++; 
                }
                mp[j].push_back(cnt);
            }
        }

        if(x > 1) mp[x].push_back(1);
    }

    ll ans = 1;
    for(auto &[p, v]: mp){
        if(v.size() < n - 1) continue;
        std::sort(v.begin(), v.end());
        if(v.size() == n - 1) ans *= power(p, v[0]);
        else ans *= power(p, v[1]);
    }

    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}