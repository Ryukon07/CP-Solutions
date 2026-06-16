#include <iostream>
#include <string>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::string s; std::cin >> s;

    ll zeros = 0, ones = 0;
    for(char c : s){
        if(c == '0') zeros++;
        else ones++;
    }

    if(zeros == 0) std::cout << "DRAW\n";
    else if(zeros % 2 == 0 || zeros == 1) std::cout << "BOB\n";
    else std::cout << "ALICE\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}