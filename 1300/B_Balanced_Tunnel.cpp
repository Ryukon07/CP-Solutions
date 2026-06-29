#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    std::map<ll, ll> positions;

    for(ll i = 0; i < n; i++) {
        std::cin >> a[i];
        positions[a[i]] = i + 1;
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll x; std::cin >> x;
        if(i + 1 != positions[x]){
            ans++;
            ll tmp = positions[x];
            positions[x] = i + 1;
            for(auto &p : positions){
                if(p.second >= tmp && p.first != x){
                    p.second++;
                }
            }
        }
    }
    std::cout << ans << std::endl;

}

int main(){
    solve();
}