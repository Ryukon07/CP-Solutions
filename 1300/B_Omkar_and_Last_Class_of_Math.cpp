#include <iostream>
#include <cmath>

using ll = long long;

void solve(){
    ll n; std::cin >> n;

    ll smallPrime = -1;
    for(ll i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            smallPrime = i;
            break;
        }
    }

    if(n % 2 == 0){
        std::cout << (n / 2) << " " << (n / 2) << std::endl;
    }else{
        if(smallPrime == -1){
            std::cout << 1 << " " << n - 1 << std::endl;
        }else{
            std::cout << (n / smallPrime) << " " << (n - n / smallPrime) << std::endl;
        }
    }
}

int main(){
    int t; std::cin >> t;
    while(t--) solve();
    return 0;
}