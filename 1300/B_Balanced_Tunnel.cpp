#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n), b(n);

    for(ll i = 0; i < n; i++) std::cin >> a[i];
    std::map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        std::cin >> b[i];
        mp[b[i]] = i + 1;
    }

    std::vector<ll> pos(n + 1);
    for(ll i = 1; i <= n; i++){
        pos[i] = mp[a[i-1]];
    }

    ll ans = 0, curr = 1;
    for(ll i = 1; i <= n; i++){
        if(pos[i] < curr) ans++;
        else curr = pos[i];
    }

    std::cout << ans << std::endl;

}

int main(){
    solve();
}