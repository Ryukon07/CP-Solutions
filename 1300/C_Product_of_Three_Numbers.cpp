#include <iostream>

using ll = long long;

void solve(){
    ll n; std::cin >> n;

    for(ll a = 2; a * a < n; a++){
        if(n % a == 0){
            ll rem = n / a;
            for(ll b = 2; b * b <= rem; b++){
                if(rem % b == 0 && b != a){
                    ll c = rem / b;
                    if(c != a && c != b && c > 1){
                        std::cout << "YES\n" << a << " " << b << " "<< c << "\n";
                        return;
                }
            }
        }
    }
    }
    std::cout << "NO\n";
}

int main(){

    ll t; std::cin >> t;
    while(t--) solve();

    return 0;
}