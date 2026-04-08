#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int t;
    std::cin >> t;
    while(t--){
        int n, k;
        std::cin >> n >> k;
        std::vector<int> boxes(n + 1);
        bool sorted = true;
        for(int i = 1; i <= n; i++){
            std::cin >> boxes[i];
            if(i > 1 && boxes[i] < boxes[i - 1]){
                sorted = false;
            }
        }

        if(k == 1){
            if(sorted){
                std::cout << "YES" << std::endl;
            }else{
                std::cout << "NO" << std::endl;
            }
        }else{
            std::cout << "YES" << std::endl;
        }

    }

    return 0;
}