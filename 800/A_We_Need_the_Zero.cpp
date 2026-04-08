#include <iostream>
#include <vector>

void solve(){
    int n; std::cin >> n;

    int totalXOR = 0;
    for(int i = 0; i < n; i++){
        int x; std::cin >> x;
        totalXOR ^= x;
    }

    if(n % 2 != 0){
        std::cout << totalXOR << std::endl;
    }else{
        if(totalXOR == 0){
            std::cout << 0 << std::endl;
        }else{
            std::cout << -1 << std::endl;
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