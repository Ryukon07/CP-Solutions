#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

void solve(){
    int n, k; std::cin >> n >> k;
    std::string s; std::cin >> s;
    std::vector<int> prefix(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefix[i + 1] = prefix[i] + (s[i] == 'W');

    }

    int ans = INT_MAX;
    for(int i = 0; i <= n - k; i++){
        ans = std::min(ans, prefix[i + k] - prefix[i]);
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