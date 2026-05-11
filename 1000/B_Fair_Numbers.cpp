#include <iostream>

using ll = long long;

bool check(ll n){
    ll temp = n;
    while(temp != 0){
        ll x = temp % 10;
        if(x != 0 && n % x != 0){
            return false;
        }
        temp /= 10;
    }
    return true;
}

void solve(){
    ll n; std::cin >> n;

    while(!check(n)){
        n++;
    }

    std::cout << n << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}