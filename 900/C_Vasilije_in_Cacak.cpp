#include <iostream>

void solve(){
    long long n, k, x;
    std::cin >> n >> k >> x;

    long long minSum = (k * (k + 1)) / 2;
    long long maxSum = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;

    if(x >= minSum && x <= maxSum){
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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