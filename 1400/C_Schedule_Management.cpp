#include <iostream>
#include <vector>

using ll = long long;

bool check(const std::vector<ll>& cnt, ll mid, ll m){
    ll cap = 0, n = cnt.size() - 1;
    for(ll i = 1; i <= n; i++){
        ll min = std::min(cnt[i], mid);
        cap += min + (mid - min) / 2;
        if(cap >= m) return true;
    }
    return cap >= m;
}

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<ll> a(m), cnt(n + 1, 0);
    for(ll i = 0; i < m; ++i){
        std::cin >> a[i];
        cnt[a[i]]++;
    }

    ll low = 0, high = 1e18, ans = -1;
    while(low <= high){
        ll mid = low + (high - low) / 2;
        if(check(cnt, mid, m)){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}