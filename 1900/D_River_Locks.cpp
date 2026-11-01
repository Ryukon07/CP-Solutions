#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    ll sum = 0, minTime = 0;
    for(ll i = 1; i <= n; i++){
        ll x; std::cin >> x;
        sum += x;
        ll required = (sum + i - 1) / i;
        minTime = std::max(minTime, required);
    }

    ll q; std::cin >> q;
    while(q--){
        ll t; std::cin >> t;
        if(t < minTime) std::cout << "-1\n";
        else{
            ll ans = (sum + t - 1) / t;
            std::cout << ans << "\n";
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}