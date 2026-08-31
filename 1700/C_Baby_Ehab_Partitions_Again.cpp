#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    int n; std::cin >> n;
    std::vector<int> a(n);
    ll total = 0;
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        total += a[i];
    }

    if(total % 2){
        std::cout << 0 << "\n";
        return;
    }

    ll target = total / 2;

    std::vector<bool> dp(target + 1, false);
    dp[0] = true;
    for(int i = 0; i < n; i++) for(int j = target; j >= a[i]; j--) if(dp[j - a[i]]) dp[j] = true;

    if(!dp[target]){
        std::cout << 0 << "\n";
        return;
    }

    while(true){
        for(ll i = 0; i < n; i++){
            if(a[i] % 2){
                std::cout << 1 << "\n" << i + 1 << "\n";
                return;
            }
        }

        for(ll i = 0; i < n; i++) a[i] /= 2;
    }
    
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}