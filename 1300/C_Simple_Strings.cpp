#include <iostream>
#include <string>

using ll = long long;

void solve(){
    std::string s; std::cin >> s;
    ll n = s.size();
    
    for(ll i = 1; i < n; i++){
        if(s[i] == s[i-1]){
            for(char c = 'a'; c <= 'z'; c++){
                if(c != s[i-1] && (i + 1 >= n || c != s[i+1]) ){
                    s[i] = c;
                    break;
                }
            }
        }
    }

    std::cout << s << "\n";

}

int main(){
    solve();
}