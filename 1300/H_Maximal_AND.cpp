#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, k; std::cin >> n >> k;
    std::vector<ll> a(n);

    for(ll i = 0; i < n; i++) std::cin >> a[i];

    ll ans = 0;
    for(int i = 30; i >= 0; i--){
        ll need = 0;
        for(ll x: a) if(((x >> i) & 1) == 0) need++;

        if(need <= k){
            ans |= (1LL << i);
            k -= need;
        }

    }
    std::cout << ans << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}