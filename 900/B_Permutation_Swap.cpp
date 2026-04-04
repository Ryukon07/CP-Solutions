#include <iostream>
#include <vector>
#include <numeric>

void solve(){
    int n; std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    int ans = abs(a[0] - 1);
    for(int i = 1; i < n; i++){
        ans = std::gcd(ans, abs(a[i] - (i + 1)));
    }

    std::cout << ans << "\n";

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}