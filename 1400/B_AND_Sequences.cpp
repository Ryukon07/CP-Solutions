#include <iostream>
#include <vector>

using ll = long long;
const ll MOD = 1e9 + 7;

ll factorial(ll n){
    ll res = 1;
    for(ll i = 2; i <= n; i++) res = (res * i) % MOD;
    return res;
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n); ll totalAND = (1LL << 60) - 1;
    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        totalAND &= a[i];
    }

    ll nums = 0;
    for(ll i = 0; i < n; i++) if(a[i] == totalAND) nums++;
    if(nums < 2) {
        std::cout << 0 << "\n";
        return;
    }
    ll ans = (nums * (nums - 1)) % MOD;
    for(ll i = 0; i < n - 2; i++) ans = (ans * (i + 1)) % MOD;
    std::cout << ans << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}