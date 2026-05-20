#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    std::string s; std::cin >> s;
    ll n = s.size();
    ll maxLen = 0;
    ll i = 0; 

    while(i < n){
        if(s[i] == '0'){
            i++;
            continue;
        }

        ll j = i + 1;
        while(j < n && s[j] == '1') j++;
        maxLen = std::max(maxLen, j - i);
        i = j;
    }

    if(maxLen == n) {std::cout << n * n << "\n"; return;}

    if(s[0] == '1' && s[n - 1] == '1'){
        ll i = 0, len = 0;
        while(i < n && s[i] == '1') {len++; i++;}
        ll j = n - 1;
        while(j >= 0 && s[j] == '1') {len++; j--;}
        maxLen = std::max(maxLen, len);
    }

    maxLen++;
    std::cout << (maxLen + 1) / 2 * (maxLen / 2) << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}