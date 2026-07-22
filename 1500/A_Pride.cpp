#include <iostream>
#include <vector>
#include <numeric>

using ll = long long;

void solve(){
    ll n;  std::cin >> n;
    std::vector<ll> a(n);

    ll ones = 0;

    for(ll i = 0; i < n; ++i) {
        std::cin >> a[i];
        if(a[i] == 1) ones++;
    }

    if(ones > 0){
        std::cout << (n - ones) << "\n";
        return;
    }

    ll minLen = 1e9;

    for(ll i = 0; i < n; i++){
        ll curr = a[i];
        for(ll j = i + 1; j < n; j++){
            curr = std::gcd(curr, a[j]);
            if(curr == 1){
                ll len = j - i + 1;
                minLen = std::min(minLen, len);
                break;
            }
        }
    }

    if(minLen == 1e9){
        std::cout << "-1\n";
        return;
    }else{
        std::cout << (minLen - 1 + n - 1) << "\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}