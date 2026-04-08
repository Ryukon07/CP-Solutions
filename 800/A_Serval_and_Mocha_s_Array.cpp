#include <iostream>
#include <string>
#include <vector>
#include <numeric>


void solve(){
    int n; std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];

    bool flag = false;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(std::gcd(a[i], a[j]) <= 2){
                flag = true;
                break;
            }
        }
    }

    if(flag) std::cout << "Yes\n";
    else std::cout << "No\n";

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}