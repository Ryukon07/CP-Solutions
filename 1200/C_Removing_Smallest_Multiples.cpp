#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    
    std::vector<bool> isRemoved(n + 1, false);
    ll ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            if(s[j-1] == '1') break;
            if(isRemoved[j]) continue;
            else{
                isRemoved[j] = true;
                ans += i;
            }
        }
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