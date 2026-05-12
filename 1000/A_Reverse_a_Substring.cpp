#include <iostream>
#include <string>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::string s; std::cin >> s;

    std::string temp = s;
    std::sort(temp.begin(), temp.end());

    if(temp == s){
        std::cout << "NO\n";
        return;
    }

    ll l = 0;
    while(l < n && s[l] == temp[l]) l++;

    ll r = l;
    for(int i = l + 1; i < n; i++){
        if(s[i] == temp[l]) r = i;
    }

    std::cout << "YES\n";
    std::cout << l + 1 << " " << r + 1 << "\n";

}

int main(){
    solve();
}