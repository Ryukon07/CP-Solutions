#include <iostream>
#include <vector>
#include <algorithm>

void solve(){
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n), minNeeded(n);

    int evenCount = 0;

    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        
        if(a[i] % k == 0){
            minNeeded[i] = 0;
        }else{
            minNeeded[i] = k - (a[i] % k);
        }

        if(a[i] % 2 == 0){
            evenCount++;
        }

    }

    int ans = *std::min_element(minNeeded.begin(), minNeeded.end());

    if(k == 4){
        if(evenCount >= 2){
            ans = std::min(ans, 0);
        }else if (evenCount == 1){
            ans = std::min(ans, 1);
        }else if (evenCount == 0){
            ans = std::min(ans, 2);
        }
    }

    std::cout << ans << std::endl;

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}