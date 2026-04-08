#include <iostream>

void solve(){
    int n; std::cin >> n;
    for(int i = 0; i < n; i++){
        int x; std::cin >> x;
    }



    if(n % 2 == 0){
        std::cout << 2 << std::endl;
        std::cout << 1 << " " << n << std::endl;
        std::cout << 1 << " " << n << std::endl;
    }else{
        std::cout << 3 << std::endl;
        std::cout << 1 << " " << n - 1 << std::endl;
        std::cout << 1 << " " << n << std::endl;
        std::cout << 1 << " " << n << std::endl;   
    }
}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}