#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::vector<std::pair<ll, ll>> diffs(n);
    for(ll i = 0; i < n; i++){
        diffs[i] = {a[i] - (i + 1), i};
    }
    std::sort(diffs.begin(), diffs.end());

    ll ans = 0, x = 0;
    for(ll i = 0; i < n;){
        x = diffs[i].first;
        ll temp = 0;
        while(i < n && diffs[i].first == x){
            temp += a[diffs[i].second];
            i++;
        }

        ans = std::max(ans, temp);
    }

    std::cout << ans << "\n";

}

int main(){
    solve();
}