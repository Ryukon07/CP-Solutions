#include <iostream>
#include <vector>
#include <cmath>

void solve(){
    int n; std::cin >> n;
    std::vector<int> a(n);

    long long countOfZeros = 0, countOfOnes = 0;

    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        if(a[i] == 0) countOfZeros++;
        else if(a[i] == 1) countOfOnes++;
    }
    
    long long ans = pow(2, countOfZeros) * countOfOnes;
    std::cout << ans << std::endl;

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}