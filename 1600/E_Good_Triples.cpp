#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    std::string s; std::cin >> s;

    ll ans = 1;
    for(ll i = 0; i < s.size(); i++){
        ll num = s[i] - '0';
        ans *= (num + 1) * (num + 2) / 2;
    }

    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
}