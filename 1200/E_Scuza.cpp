#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n, q; std::cin >> n >> q;
    std::vector<ll> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::vector<ll> prefSum(n), maxHeights(n);
    prefSum[0] = a[0];
    maxHeights[0] = a[0];
    for(int i = 1; i < n; i++){
        prefSum[i] = prefSum[i - 1] + a[i];
        maxHeights[i] = std::max(maxHeights[i - 1], a[i]);
    }

    for(ll i = 0; i < q; i++){
        ll x; std::cin >> x;
        auto it = std::upper_bound(maxHeights.begin(), maxHeights.end(), x);
        ll val = (it - maxHeights.begin()) - 1;

        if(val < 0){
            std::cout << "0 ";
        }else{
            std::cout << prefSum[val] << " ";
        }
    }
    std::cout << "\n";

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}