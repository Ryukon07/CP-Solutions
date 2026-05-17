#include <iostream>
#include <vector>

using ll = long long;

bool check(const std::vector<ll>& a, ll x, ll mid){
    ll n = a.size();
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        if(a[i] < mid) sum += (mid - a[i]);
        if(sum > x) return false;
    }

    return sum <= x;
}

void solve(){
    ll n, x; std::cin >> n >> x;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    ll ans = 0, l = 0, r = 4e9;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        if(check(a, x, mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
    return 0;
}