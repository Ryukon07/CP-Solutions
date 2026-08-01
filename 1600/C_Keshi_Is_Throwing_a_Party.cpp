#include <iostream>
#include <vector>

using ll = long long;

bool check(ll mid, const std::vector<ll>& a, const std::vector<ll>& b){
    ll x = 0, n = a.size();
    for(ll i = 0; i < n; i++){
        if(x <= b[i] && mid - x - 1 <= a[i]) x++;
    }
    return x >= mid;
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n), b(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i] >> b[i];

    ll low = 0, high = n, ans = 1;
    while(low <= high){
        ll mid = low + (high - low) / 2;

        if(check(mid, a, b)){ans = mid; low = mid + 1;}
        else high = mid - 1;
    }

    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}