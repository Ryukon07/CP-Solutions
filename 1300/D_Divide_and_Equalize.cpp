#include <iostream>
#include <vector>
#include <map>

using ll = long long;

void solve(){
    ll n; std::cin >> n;

    std::map<ll, ll> freq;

    for(ll i = 0; i < n; i++){
        ll x; std::cin >> x;
        for(ll j = 2; j * j <= x; j++){
            while(x % j == 0){
                freq[j]++;
                x /= j;
            }
        }
        if(x > 1) freq[x]++;
        freq[1]++;
    }

    bool ok = true;
    for(auto& [key, value] : freq){
        if(value % n != 0){
            ok = false;
            break;
        }
    }

    if(ok) std::cout << "YES\n";
    else std::cout << "NO\n";

}

int main(){

    ll t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}