#include <iostream>
#include <vector>

using ll = long long;

ll xorSum(ll n){
    ll a = n % 4;
    if(a == 0) return n;
    else if(a == 1) return 1;
    else if(a == 2) return n + 1;
    else return 0;
}

void solve(){
    ll a, b; std::cin >> a >> b;

    ll xors = xorSum(a - 1);

    if(xors == b) std::cout << a << "\n";
    else if((xors ^ b) != a) std::cout << a + 1 << "\n";
    else std::cout << a + 2 << "\n";

}

int main(){

    ll t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}