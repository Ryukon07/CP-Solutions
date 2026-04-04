#include <iostream>
#include <vector>
#include <map>

void solve(){

    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    std::map<int, int> freq;
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
        freq[arr[i]]++;
    }

    if(freq.size() > 2){
        std::cout << "No" << std::endl;
    }

    if(freq.size() == 2){
        auto first = freq.begin();
        auto second = std::next(freq.begin());
        if(n % 2 == 0){
            if(first->second == second->second){
                std::cout << "Yes" << std::endl;
            } else {
                std::cout << "No" << std::endl;
            }
        }else{
            if(first->second == second->second + 1 || second->second == first->second + 1){
                std::cout << "Yes" << std::endl;
            } else {
                std::cout << "No" << std::endl;
            }
        }
    }

    if(freq.size() == 1){
        std::cout << "Yes" << std::endl;
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