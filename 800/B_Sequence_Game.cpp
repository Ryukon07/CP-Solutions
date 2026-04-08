#include <iostream>
#include <vector>

void solve(){
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i = 0 ; i< n; i++) std::cin >> arr[i];

    std::vector<int> ans;
    ans.push_back(arr[0]);
    for(int i = 1;  i < n; i++){
        if(arr[i] < ans.back()){
            ans.push_back(arr[i]);
            ans.push_back(arr[i]);
        }else{
            ans.push_back(arr[i]);
        }
    }

    std::cout << ans.size() << std::endl;
    for(int i = 0; i < ans.size(); i++){
        std::cout << ans[i] << " ";
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