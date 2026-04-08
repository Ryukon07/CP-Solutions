#include <iostream>
#include <vector>

void solve(){
    int a, b, n; std::cin >> a >> b >> n;
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    int ans = b ;
    for(int i = 0; i < n; i++){
        ans += std::min(arr[i], a-1);
    }

    std::cout << ans << "\n";
}

int main(){

    int t;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}