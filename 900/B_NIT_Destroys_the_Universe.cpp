#include <iostream>
#include <vector>

void solve(){
    int n; std::cin >> n;
    std::vector<long long> a(n);

    int zero_count = 0;

    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        if(a[i] == 0) zero_count++;
    }

    bool foundZero = false;
    int l = 0, r = n - 1;

    while(a[l] == 0) l++;
    while(a[r] == 0) r--;

    for(int i = l; i <= r; i++) {
        if(a[i] == 0) {
            foundZero = true;
            break;
        }
    }

    if(zero_count == n){
        std::cout << 0 << std::endl;
    }else if(foundZero == false){
        std::cout << 1 << std::endl;
    }else{
        std::cout << 2 << std::endl;
    }

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}