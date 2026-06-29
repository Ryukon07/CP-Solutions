#include <iostream>
#include <vector>

using ll = long long;

ll kadane(std::vector<ll> &a){
    ll m1 = a[0], c1 = a[0];
    for(ll i = 1; i < a.size() - 1; i++) {
        c1 = std::max(a[i], c1 + a[i]);
        m1 = std::max(m1, c1);
    }

    ll m2 = a[1], c2 = a[1];
    for(ll i = 2; i < a.size(); i++) {
        c2 = std::max(a[i], c2 + a[i]);
        m2 = std::max(m2, c2);
    }
    return std::max(m1, m2);
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);

    ll total = 0;
    for(ll i = 0; i < n; i++) {
        std::cin >> a[i];
        total += a[i];
    }

    ll maxSubarraySum = kadane(a);

    if(maxSubarraySum >= total) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}