#include <iostream>

void solve(){
    long long n, k;
    std::cin >> n >> k;

    if(n % 2 == 0){
        std::cout << "YES" << std::endl;
    }else{
        if((n - k) % 2 == 0){
            std::cout << "YES" << std::endl;
        }else{
            if((n - 2 * k) % 2 == 0 && n >= 2 * k){
                std::cout << "YES" << std::endl;
            }else{
                std::cout << "NO" << std::endl;
            }
        }
    }

}

int main(){

    int t;
    std::cin >> t;
    while(t--){
        solve();
    }
    return 0;
}