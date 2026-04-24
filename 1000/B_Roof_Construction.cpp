#include <iostream>
#include <vector>

void solve(){
    int n; std::cin >> n; 
    std::vector<int> a;

    int mtp = 1;
    while(mtp * 2 < n) mtp *= 2;

    int temp = mtp - 1;
    while(temp >= 0) a.push_back(temp), temp--;

    while(mtp < n) a.push_back(mtp), mtp++;

    for(int i = 0; i < n; i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}