#include <iostream>

void solve(){
    long long n; std::cin >> n;

    if(n & (n - 1)) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}