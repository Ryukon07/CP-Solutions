#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for(int i = 0; i < n; i++){
            std::cin >> arr[i];
        }

        std::vector<int> temp = arr;
        std::sort(temp.begin(), temp.end());

        if(arr[0] != 1){
            std::cout << "NO" << std::endl;
            continue;
        }

        if(arr == temp){
            std::cout << "YES" << std::endl;
            continue;
        }

        for(int i = 1; i < n-1; i++){
            for(int j = 1; j < n - 1; j++){
                if(arr[j] > arr[j+1]){
                    std::swap(arr[j], arr[j+1]);
                }
            }
        }

        if(arr == temp){
            std::cout << "YES" << std::endl;
        }else{
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}