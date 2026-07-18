#include <iostream>
#include <string>
#include <vector>

using ll = long long;

void solve(){
    ll n, k; std::cin >> n >> k;
    std::string s; std::cin >> s;

    std::vector<char> ans(k, '?');
    for(ll i = 0; i < n; i++){
        if(s[i] != '?'){
            if(ans[i % k] == '?') ans[i % k] = s[i];
            else if(ans[i % k] != s[i]){
                std::cout << "NO\n";
                return;
            }
        }
    }

    ll cnt0 = 0, cnt1 = 0;
    for(ll i = 0; i < k; i++){
        if(ans[i] == '0') cnt0++;
        else if(ans[i] == '1') cnt1++;
    }

    if(cnt0 > k / 2 || cnt1 > k / 2){
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}