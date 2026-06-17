#include <iostream>
#include <vector>
#include <map>

using ll = long long;

void solve(){
    int n; std::cin >> n;
    std::map<int, ll> freq;
    for(int i = 0; i < n; i++){
        int x; std::cin >> x;
        int msb = 31 - __builtin_clz(x);
        freq[msb]++;
    }

    ll ans = 0;
    for(auto [msb, count] : freq){
        ans += count * (count - 1) / 2;
    }

    std::cout << ans << "\n";
}

int main(){
    int t; std::cin >> t;
    while(t--) solve();
}