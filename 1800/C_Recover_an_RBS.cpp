#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    std::string s; std::cin >> s;
    ll n = s.size();

    ll open = n / 2, close = n / 2;
    std::vector<ll> idx;

    for(ll i = 0; i < n; i++){
        if(s[i] == '(') open--;
        else if(s[i] == ')') close--;
        else idx.push_back(i);
    }

    for(ll i = 0; i < idx.size(); i++){
        if(i < open) s[idx[i]] = '(';
        else s[idx[i]] = ')';
    }

    if(open == 0 || open == idx.size()){
        std::cout << "YES\n";
        return;
    }

    std::swap(s[idx[open - 1]], s[idx[open]]);

    ll balance = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] == '(') balance++;
        else balance--;

        if(balance < 0){
            std::cout << "YES\n";
            return;
        }
    }

    std::cout << "NO\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;

}