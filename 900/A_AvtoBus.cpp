#include <iostream>

void solve(){
    long long n; std::cin >> n;

    if(n < 4 || n % 2 == 1){
        std::cout << -1 << std::endl;
    }else{
        long long max = n / 4;
        long long min = (n + 5) / 6;
        std::cout << min << " " << max << std::endl;
    }

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}