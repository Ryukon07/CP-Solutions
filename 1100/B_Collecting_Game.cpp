#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<std::pair<ll, ll>> a(n);
    for(ll i = 0; i < n; i++){
        std::cin >> a[i].first;
        a[i].second = i;
    }

    std::sort(a.begin(), a.end());
    std::vector<ll> prefixSum(n);
    for(ll i = 0; i < n; i++) prefixSum[i] = a[i].first + (i > 0 ? prefixSum[i - 1] : 0);

    std::vector<ll> temp(n), ans(n);

    temp[n - 1] = n - 1;
    for(ll i = n - 2; i >= 0; i--){
        if(prefixSum[i] >= a[i + 1].first) temp[i] = temp[i + 1];
        else temp[i] = i;
    }

    for(ll i = 0; i < n; i++) ans[a[i].second] = temp[i];

    for(ll i = 0; i < n; i++) std::cout << ans[i] << " ";
    std::cout << "\n";

}

int main(){
    int t; std::cin >> t;
    while(t--){
        solve();
    }
}