#include <iostream>
#include <vector>

void solve(){
    int n; std::cin >> n;
    std::vector<int> numbers(n);
    std::vector<int> prefix2(n);
    int total2 = 0;

    for(int i = 0; i < n; i++){
        std::cin >> numbers[i];
        if(numbers[i] == 2){
            total2++;
        }
        prefix2[i] = total2;
    }

    if(total2 % 2 != 0){
        std::cout << -1 << std::endl;
        return;
    }else{
        int half2 = total2 / 2;
        for(int i = 0; i < n; i++){
            if(prefix2[i] == half2){
                std::cout << i + 1 << std::endl;
                return;
            }
        }
    }

    std::cout << -1 << std::endl;

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}