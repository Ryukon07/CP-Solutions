#include <iostream>
#include <string>

void solve(){
    std::string s; std::cin >> s;
    int n = s.size();

    int zeros = 0, ones = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') zeros++;
        else ones++;
    }

    int check = std::min(zeros, ones);

    if(check % 2 == 1) std::cout << "DA\n";
    else std::cout << "NET\n";
}

int main(){
    int t; std::cin >> t;
    while(t--){
        solve();
    }
}