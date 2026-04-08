#include <iostream>

void solve(){
    int n; std::cin >> n;
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        int x; std::cin >> x;
        ans += x;
    }

    std::cout << -ans << std::endl;
}

int main(){

    int t;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}