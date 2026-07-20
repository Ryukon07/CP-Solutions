#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

std::vector<ll> onesCount(const std::vector<ll>& arr) {
    std::vector<ll> counts;
    for(ll i = 0; i < arr.size(); i++) {
        ll len = 0;
        if(arr[i] == 1) {
            while(i < arr.size() && arr[i] == 1) {
                len++;
                i++;
            }
            counts.push_back(len);
        }
    }
    return counts;
}

ll countWays(const std::vector<ll>& counts, ll length, const std::vector<ll>& prefix) {
    auto it = std::lower_bound(counts.begin(), counts.end(), length);
    if(it == counts.end()) return 0;

    ll idx = it - counts.begin();
    ll blocks = counts.size() - idx;

    ll sum = prefix[idx];
    return sum - (length - 1) * blocks;

}

void solve(){
    ll n, m, k; std::cin >> n >> m >> k;
    std::vector<ll> a(n), b(m);
    for(ll i = 0; i < n; i++) std::cin >> a[i];
    for(ll i = 0; i < m; i++) std::cin >> b[i];

    std::vector<ll> aOnes = onesCount(a);
    std::vector<ll> bOnes = onesCount(b);

    std::sort(aOnes.begin(), aOnes.end());
    std::sort(bOnes.begin(), bOnes.end());

    std::vector<ll> prefixA(aOnes.size() + 1, 0), prefixB(bOnes.size() + 1, 0);
    prefixA[aOnes.size()] = 0;
    for(ll i = aOnes.size() - 1; i >= 0; i--) {
        prefixA[i] = prefixA[i + 1] + aOnes[i];
    }
    prefixB[bOnes.size()] = 0;
    for(ll i = bOnes.size() - 1; i >= 0; i--) {
        prefixB[i] = prefixB[i + 1] + bOnes[i];
    }

    ll ans = 0;
    for(ll i = 1; i * i <= k; i++){
        if(k % i == 0){
            ll j = k / i;
            
            ll waysA = countWays(aOnes, i, prefixA);
            ll waysB = countWays(bOnes, j, prefixB);
            ans += waysA * waysB;

            if(i != j){
                waysA = countWays(aOnes, j, prefixA);
                waysB = countWays(bOnes, i, prefixB);
                ans += waysA * waysB;
            }
        }
    }

    std::cout << ans << "\n";

}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}