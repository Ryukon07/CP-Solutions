#include <iostream>

using ll = long long;

void solve(){
    ll n; std::cin >> n;

    if(n % 2 == 0){
        std::cout << (n /2 + 1) * (n / 2 + 1) << std::endl;
    }else{
        std::cout << ((n / 2 + 1) * (n / 2 + 2))*2 << std::endl;
    }
}

int main(){
    solve();
    return 0;
}