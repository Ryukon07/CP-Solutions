#include <iostream>
#include <vector>

using ll = long long;

const ll MOD = 998244353;

void solve(){
    std::string s; std::cin >> s;
    ll n = s.size();

    std::vector<ll> sameLen;

    ll count = 0;
    for(ll i = 1; i < n; i++){
        if(s[i] == s[i-1]){
            count++;
            while(i < n && s[i] == s[i-1]){
                count++;
                i++;
            }
        }
        if(count > 0) sameLen.push_back(count);
        count = 0;
    }

    ll m = sameLen.size();
    if(m == 0){
        std::cout << "0" << " " << "1" << "\n";
        return;
    }

    ll ops = 0, sub = 1;

    for(ll l: sameLen){
        ops += l - 1;
        sub = (sub * l) % MOD;
    }

    for(ll i = 2; i <= ops; i++){
        sub = (sub * i) % MOD;
    }

    std::cout << ops << " " << sub << "\n";

}

int main(){

    ll t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}