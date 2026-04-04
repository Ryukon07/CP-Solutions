#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    bool isZero = false;
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
        if(arr[i] == 0){
            isZero = true;
        }
        if(arr[i] < 0){
            arr[i] = -arr[i];
        }
    }

    
    if(isZero){
        std::cout << 0 << std::endl;
        return 0;
    }

    auto it = std::min_element(arr.begin(), arr.end());
    std::cout << *it << std::endl;

    return 0;

}