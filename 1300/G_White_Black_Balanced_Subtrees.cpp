#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n + 1); a[1] = 1;
    for(ll i = 2; i <= n; i++) std::cin >> a[i];
    std::string s; std::cin >> s;

    std::vector<ll> balance(n + 1, 0);
    balance[1] = (s[0] == 'W' ? -1 : 1);

    for(ll i = 2; i <= n; i++){
        ll tmp = i;
        ll color = (s[i - 1] == 'W' ? -1 : 1);
        while(tmp != 1){
            balance[tmp] += color;
            tmp = a[tmp];
        }
        balance[1] += color;
    }

    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        if(balance[i] == 0) ans++;
    }

    std::cout << ans << "\n";

}

int main(){

    ll t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}