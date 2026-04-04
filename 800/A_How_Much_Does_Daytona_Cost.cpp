#include <iostream>
#include <vector>

void solve(){
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    bool isK = false;
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
        if(arr[i] == k){
            isK = true;
        }
    }

    if(isK){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
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