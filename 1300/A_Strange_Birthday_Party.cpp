#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<ll> k(n), c(m);
    for(ll i = 0; i < n; i++) std::cin >> k[i];
    for(ll i = 0; i < m; i++) std::cin >> c[i];

    std::sort(k.rbegin(), k.rend());

    ll ans = 0, ptr = 0;
    for(ll i = 0; i < n; i++){
        if(ptr < m && c[ptr] <= c[k[i]-1]){
            ans += c[ptr];
            ptr++;
        }else{
            ans += c[k[i]-1];
        }
    }
    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}