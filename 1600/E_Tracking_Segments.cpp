#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

bool check(const std::vector<std::pair<ll, ll>>& segments, ll mid, ll n, ll m, const std::vector<ll>& queries){
    std::vector<ll> a(n + 1, 0);
    for(ll i = 0; i < mid; i++) a[queries[i]]++;

    std::vector<ll> prefixSum(n + 1, 0);
    for(ll i = 1; i <= n; i++) prefixSum[i] = prefixSum[i - 1] + a[i];

    for(auto &seg : segments){
        ll l = seg.first, r = seg.second;
        ll ones = prefixSum[r] - prefixSum[l - 1];
        ll total = r - l + 1;
        if(ones * 2 > total) return true;
    }
    return false;

}

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<std::pair<ll, ll>> segments(m);
    for(ll i = 0; i < m; i++) std::cin >> segments[i].first >> segments[i].second;

    ll q; std::cin >> q;
    std::vector<ll> queries(q);

    for(ll i = 0; i < q; i++) std::cin >> queries[i];
    
    ll low = 1, high = q, ans = -1;
    while(low <= high){
        ll mid = low + (high - low) / 2;
        if(check(segments, mid, n, m, queries)){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;
}