#include <iostream>
#include <vector>

void solve(){
    std::string s; std::cin >> s;
    long long n = s.size();

    std::vector<std::string> candidates = {"00", "25", "50", "75"};
    long long ans = 1e18;
    for(const std::string& candidate : candidates){
        long long idx1 = -1, idx2 = -1;
        for(long long i = n - 1; i >= 0; i--){
            if(s[i] == candidate[1] && idx1 == -1) idx1 = i;
            else if(s[i] == candidate[0] && idx1 != -1 && idx2 == -1) idx2 = i;
        }

        if(idx1 != -1 && idx2 != -1){
            ans = std::min(ans, (n - 1 - idx1) + (idx1 - 1 - idx2));
        }
    }

    if(ans == 1e18) std::cout << -1 << std::endl;
    else std::cout << ans << std::endl;


}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}