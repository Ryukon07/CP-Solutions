#include <iostream>
#include <string>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    char c; std::cin >> c;
    std::string s; std::cin >> s;

    bool all_equal = true;
    for(ll i = 0; i < n; i++){
        if(s[i] != c){
            all_equal = false;
            break;
        }
    }

    if(all_equal){
        std::cout << 0 << "\n";
        return;
    }

    ll x = -1;
    for(ll i = 2; i <= n; i++){
        bool multiple_of_i = true;
        for(ll j = i; j <= n; j += i){
            if(s[j - 1] != c){
                multiple_of_i = false;
                break;
             }
        }
        if(multiple_of_i){
            x = i;
            break;
        }
    }

    if(x != -1){
        std::cout << 1 << "\n";
        std::cout << x << "\n";
    }else{
        std::cout << 2 << "\n";
        std::cout << n - 1 << " " << n << "\n";
    }
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}