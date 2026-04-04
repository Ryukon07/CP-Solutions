#include <iostream>
#include <vector>

void solve(){
    int n; std::cin >> n;
    std::vector<int> arr(n);
    int count1 = 0; int countNeg1 = 0;
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
        if(arr[i] == 1) count1++;
        else if(arr[i] == -1) countNeg1++;
    }

    if (count1 >= countNeg1){
        if(countNeg1 % 2 == 0){
            std::cout << 0 << std::endl;
        }else{
            std::cout << 1 << std::endl;
        }
    }else{
        int ops = 0;
        while(count1 < countNeg1){
            count1++;
            countNeg1--;
            ops++;
        }

        if(countNeg1 % 2 == 0){
            std::cout << ops << std::endl;
        }else{
            std::cout << ops + 1 << std::endl;
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