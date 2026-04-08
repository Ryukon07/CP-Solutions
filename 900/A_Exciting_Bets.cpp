#include <iostream>
#include <algorithm>

void solve(){
    long long a, b; std::cin >> a >> b;

    if(a == b) {
        std::cout << 0 << " " << 0 << std::endl;
        return;
    }

    long long gcd = std::abs(a - b);
    long long moves = std::min(a % gcd, gcd - (a % gcd));
    std::cout << gcd << " " << moves << std::endl;

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}