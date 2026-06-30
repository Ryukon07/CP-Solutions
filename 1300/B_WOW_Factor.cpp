#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    std::string s; std::cin >> s;
    ll n = s.size();

    std::vector<ll> prefW(n + 1, 0);
    for(ll i = 0; i < n; i++){
        prefW[i + 1] = prefW[i];
        if(i + 1 < n && s[i] == 'v' && s[i + 1] == 'v') prefW[i + 1]++;
    }

    ll ans = 0, total = prefW[n];
    for(ll i = 0; i < n; i++){
        if(s[i] == 'o'){
            ans += prefW[i] * (total - prefW[i]);
        }
    }

    std::cout << ans << std::endl;

}

int main(){
    solve();
}