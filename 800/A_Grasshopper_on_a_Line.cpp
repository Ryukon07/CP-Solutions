#include <iostream>
#include <vector>

void solve(){
    int x, k;
    std::cin >> x >> k;

    std::vector<int> ans;

    if(x % k != 0){
        std::cout << 1 << std::endl;
        std::cout << x << std::endl;
    }else{
        std::cout << 2 << std::endl;
        std::cout << x - 1 << " " << 1 << std::endl;
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