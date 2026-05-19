#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, x; std::cin >> n >> x;
    ll ans = 0;

    for(ll i = 0; i < 3; i++){
        for(ll j = 0; j < n; j++){
            ll a; std::cin >> a;
            
            if((a | x) == x){
                ans |= a;
            }else{
                for(ll k = j + 1; k < n; k++) std::cin >> a;
                break;
            }
        }
    }

    if(ans == x) std::cout << "Yes\n";
    else std::cout << "No\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}