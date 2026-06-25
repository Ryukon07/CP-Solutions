#include <iostream>

using ll = long long;

ll summation(ll n, ll i){
    if(n >= i) return (i * (i + 1)) / 2;
    else return ((n * n) - (2*n - i - 1) * (2*n - i) / 2);
}

void solve(){
    ll n, x; std::cin >> n >> x;

    if(x >= (n * n)) {
        std::cout << 2 * n - 1 << "\n";
        return;
    }

    ll ans = 0;
    ll low = 1, high = 2 * n - 1;
    while(low <= high){
        ll mid = low + (high - low) / 2;
        if(summation(n, mid) >= x){
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}