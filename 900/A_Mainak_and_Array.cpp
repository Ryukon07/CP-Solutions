#include <iostream>
#include <vector>
#include <algorithm>

void solve(){
    int n; std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];

    int ans = a[n-1] - a[0];
    for(int i = 0; i < n-1; i++){
        ans = std::max(ans, a[i] - a[i+1]);
    }

    for(int i = 1; i < n-1; i++){
        ans = std::max(ans, a[i] - a[0]);
    }

    for(int i = 0; i < n-1; i++){
        ans = std::max(ans, a[n-1] - a[i]);
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