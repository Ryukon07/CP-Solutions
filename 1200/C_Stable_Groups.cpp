#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n, k, x; std::cin >> n >> k >> x;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::sort(a.begin(), a.end());

    std::vector<ll> gaps;
    for(ll i = 1; i < n; i++){
        ll diff = a[i] - a[i - 1];
        if(diff > x) gaps.push_back((diff + x - 1) / x - 1);

    }

    std::sort(gaps.begin(), gaps.end());

    ll ans = gaps.size();

    for(ll g: gaps){
        if(k >= g) {k -= g, ans--;}
        else break;
    }

    std::cout << ans + 1 << "\n";
}

int main(){
        solve();
}