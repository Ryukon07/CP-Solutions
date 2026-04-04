#include <iostream>
#include <vector>
#include <algorithm>

void solve(){
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    
    long long temp = 1;
    long long ans = 1;

    for(int i = 1; i < n; i++){
        if(a[i] - a[i-1] <= k){
            temp++;
        }else{
            temp = 1;
        }
        ans = std::max(ans, temp);
    }

    std::cout << n - ans << std::endl;

}

int main(){

    int t;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}