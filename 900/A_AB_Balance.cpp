#include <iostream>

void solve(){
    std::string s; std::cin >> s;
    int n = s.size();

    if(s[0] != s[n-1]){
        if(s[0] == 'a') s[0] = 'b';
        else s[0] = 'a';
    }

    std::cout << s << std::endl;
}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}