#include <iostream>

void solve(){
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        std::cout << n - x + 1 << " ";
    }

    std::cout << std::endl;
}

int main(){

    int t;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}