#include <iostream>
#include <vector>

using ll = long long;

bool check(ll x, const std::vector<ll>& l, const std::vector<ll>& r, ll n){
    ll l0 = 0, h0 = 0;
    for(ll i = 0; i < n; i++){
        l0 = std::max(l0 - x, l[i]);
        h0 = std::min(h0 + x, r[i]);
        if(l0 > h0) return false;
    }
    return true;
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> l(n), r(n);
    for(ll i = 0; i < n; i++) std::cin >> l[i] >> r[i];

    ll low = 0, high = 1e9 + 1;
    while(low < high){
        ll mid = low + (high - low) / 2;
        if(check(mid, l, r, n)) high = mid;
        else low = mid + 1;
    }

    std::cout << low << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}