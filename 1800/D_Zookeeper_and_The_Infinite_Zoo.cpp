#include <iostream>

using ll = long long;

void solve(){
    ll a, b; std::cin >> a >> b;

    if(a > b){
        std::cout << "NO\n";
        return;
    }
    
    if(a == b){
        std::cout << "YES\n";
        return;
    }

    ll a0 = 0, b0 = 0;
    bool ok = true;

    while(b != 0){
        a0 += a % 2;
        b0 += b % 2;

        a /= 2;
        b /= 2;

        if(a0 < b0){
            ok = false;
            break;
        }
    }

    if(ok){
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}