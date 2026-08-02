#include <iostream>
#include <vector>
#include <string>

using ll = long long;

void solve(){
    ll n, k; std::cin >> n >> k;
    std::string s; std::cin >> s;

    std::string ans;
    std::string temp = "";

    for(ll i = 0; i < n; i++){
        temp += s[i];
        std::string temp2 = temp;
        while(temp2.size() < k) temp2 += temp;
        while(temp2.size() > k) temp2.pop_back();
        if(ans == "" || temp2 < ans) ans = temp2;
    }

    std::cout << ans << "\n";


}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}