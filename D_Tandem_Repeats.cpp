#include <iostream>
#include <string>

using ll = long long;

bool match(char a, char b){
    return (a == b || a == '?' || b == '?');
}

void solve(){
    std::string s; std::cin >> s;
    ll n = s.size();

    for(ll i = n/2; i >= 1; i--){
        ll ans = 0;
        for(ll j = 0; j + i < n; j++){
            if(match(s[j], s[j+i])) ans++;
            else ans = 0;

            if(ans == i){
                std::cout << 2 * ans << "\n";
                return;
            }
        }
    }

    std::cout << "0\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}