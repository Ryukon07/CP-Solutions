#include <iostream>

void solve(){
    int n; std::cin >> n;
    int sum = 0, max = 0;

    for(int i = 0; i < n; i++){
        int x; std::cin >> x;
        sum += x;
        max = std::max(x, max);
    }

    if(2 * max > sum){
        std::cout << "T\n";
    }else{
        if(sum % 2) std::cout << "T\n";
        else std::cout << "HL\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while(t--) solve();
}