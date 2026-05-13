#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];
    for(int i = 0; i < n; i++) std::cin >> b[i];

    std::vector<ll> longestSubA(2 * n + 1, 0), longestSubB(2 * n + 1, 0);
    ll count = 1;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1]) count++;
        else{
            longestSubA[a[i - 1]] = std::max(longestSubA[a[i - 1]], count);
            count = 1;
        }
    }
    longestSubA[a[n - 1]] = std::max(longestSubA[a[n - 1]], count);
    
    count = 1;
    for(int i = 1; i < n; i++){
        if(b[i] == b[i - 1]) count++;
        else{
            longestSubB[b[i - 1]] = std::max(longestSubB[b[i - 1]], count);
            count = 1;
        }
    }
    longestSubB[b[n - 1]] = std::max(longestSubB[b[n - 1]], count);

    ll ans = -1;
    for(int i = 1; i <= 2 * n; i++){
        ans = std::max(ans, longestSubA[i] + longestSubB[i]);
    }
    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}