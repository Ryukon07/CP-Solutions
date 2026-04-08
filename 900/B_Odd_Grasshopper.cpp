#include <iostream>

void solve(){
    long long x, n; std::cin >> x >> n;
    
    long long temp = 0;
    if(n % 4 == 0) temp = 0;
    else if(n % 4 == 1) temp = n;
    else if(n % 4 == 2) temp = -1;
    else temp = -n - 1;

    if(x % 2 == 0) std::cout << x - temp << std::endl;
    else std::cout << x + temp << std::endl;
}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}