#include <iostream>
#include <vector>
#include <algorithm>

void solve(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> diff(n-1);
    bool isSorted = true;
    bool allEqual = true;
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        if(i > 0){
            diff[i-1] = a[i] - a[i-1];
            if(diff[i-1] < 0){
                isSorted = false;
            }
            if(diff[i-1] != 0){
                allEqual = false;
            }
        }
    }

    if(allEqual){
        std::cout << 1 << std::endl;
        return;
    }else if(isSorted){
        std::cout << (*std::min_element(diff.begin(), diff.end()))/2 + 1 << std::endl;
        return;
    }else{
        std::cout << 0 << std::endl;
        return;
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