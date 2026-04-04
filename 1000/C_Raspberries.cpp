#include <iostream>
#include <vector>
#include <algorithm>

void solve(){
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n), forMin(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        if(a[i] % k == 0){
            forMin[i] = 0;
        }else{
            forMin[i] = k - (a[i] % k);
        }
    }

    int ans = *std::min_element(forMin.begin(), forMin.end());
    std::cout << ans << std::endl;
}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}