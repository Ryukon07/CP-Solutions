#include <iostream>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::string s; std::cin >> s;

    ll total = 0;
    for(ll i = 0; i < n; i++) if(s[i] == '*') total++;

    ll mid = (total + 1) / 2;
    ll count = 0, idx = -1;
    for(ll i = 0; i < n; i++){
        if(s[i] == '*') count++;
        if(count == mid){
            idx = i;
            break;
        }
    }

    ll ans = 0, usedLeft = 0, usedRight = 0;
    for(ll i = 0; i < idx; i++){
        if(s[i] == '*'){
            ans += (idx - i - 1 - usedLeft);
            usedLeft++;
        }
    }

    for(ll i = idx + 1; i < n; i++){
        if(s[i] == '*'){
            ans += (i - idx - 1 - usedRight);
            usedRight++;
        }
    }

    std::cout << ans << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}