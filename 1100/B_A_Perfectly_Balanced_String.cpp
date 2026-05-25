#include <iostream>
#include <string>
#include <set>

using ll = long long;

void solve(){
    std::string s; std::cin >> s;
    ll n = s.size();
    std::set<char> st;
    ll k;
    for(k = 0; k < n; k++){
        if(st.find(s[k]) == st.end()){
            st.insert(s[k]);
        } else {
            break;
        }
    }

    for(ll i = k; i < n; i++){
        if(s[i] != s[i - k]){
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}