#include <iostream>

using ll = long long;

void solve(){
    ll n, k; std::cin >> n >> k; k--;

    if(n % 2 == 0){
        std::cout << (k % n) + 1 << "\n";
    }else{
        ll shift = k / (n / 2);
        std::cout << (k + shift) % n + 1 << "\n";
    }

}

int main(){
    int t; std::cin >> t;
    while(t--){
        solve();
    }
}