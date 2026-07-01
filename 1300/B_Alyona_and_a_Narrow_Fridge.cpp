#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

auto idk(std::vector<ll>& a, ll h, ll mid){
    std::vector<ll> b(a.begin(), a.begin() + mid + 1);
    std::sort(b.begin(), b.end());
    ll temp = 0;
    for(ll i = mid; i >= 0; i -= 2){
        temp += b[i];
        if(temp > h) return false;
    }
    return true;
}

void solve(){
    ll n, h; std::cin >> n >> h;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; ++i) std::cin >> a[i];

    ll low = 0, high = n - 1;
    while(low <= high){
        ll mid = low + (high - low) / 2;
        if(idk(a, h, mid)) low = mid + 1;
        else high = mid - 1;
    }

    std::cout << low << "\n";

}

int main(){
    solve();
}