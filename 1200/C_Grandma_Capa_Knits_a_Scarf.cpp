#include <iostream>
#include <vector>
#include <climits>

using ll = long long;

ll check(std::string &s, char c){
    ll l = 0, r = s.size() - 1, cnt = 0;
    while(l < r){
        if(s[l] == s[r]) {l++; r--;}
        else if(s[l] == c) {cnt++; l++;}
        else if(s[r] == c) {cnt++; r--;}
        else return LLONG_MAX;
    }
    return cnt;
}

void solve(){
    ll n; std::cin >> n; 
    std::string s; std::cin >> s;

    ll ans = LLONG_MAX;

    for(char c = 'a'; c <= 'z'; c++){
        ans = std::min(ans, check(s, c));
    }

    if(ans == LLONG_MAX) std::cout << -1 << "\n";
    else std::cout << ans << "\n";

}

int main(){
    int t; std::cin >> t;
    while(t--){
        solve();
    }
}