#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using ll = long long;

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<ll> trailingZeros(n);

     ll totalLen = 0;
     for(ll i = 0; i < n; i++){
        std::string s; std::cin >> s;
        totalLen += s.size();

        ll zeroCount = 0;
        for(ll j = s.size() - 1; j >= 0; j--){
            if(s[j] == '0') zeroCount++;
            else break;
        }
        trailingZeros[i] = zeroCount;
     }

     std::sort(trailingZeros.begin(), trailingZeros.end());

    for(ll i = n - 1; i >= 0; i -= 2){
        if(trailingZeros[i] > 0) totalLen -= trailingZeros[i];
        else break;
    }

    if(totalLen > m) std::cout << "Sasha\n";
    else std::cout << "Anna\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}