#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

ll n;
std::vector<std::pair<ll, ll>> a;
std::vector<ll> byH, byW;

bool recur(ll w, ll h){
    std::vector<bool> used(n, 0);
    ll i = 0, j = 0;
    for(ll rem = n; rem > 0; rem--){
        if(h <= 0 || w <= 0) return false;
        while(i < n && used[byH[i]]) i++;
        while(j < n && used[byW[j]]) j++;

        ll fullHeight = byH[i], fullWidth = byW[j];

        if(a[fullHeight].first > h || a[fullWidth].second > w) return false;
        if(a[fullHeight].first == h){
            w -= a[fullHeight].second;
            used[fullHeight] = true;
        } else if(a[fullWidth].second == w){
            h -= a[fullWidth].first;
            used[fullWidth] = true;
        } else {
            return false;
        }
    }
   
    return h == 0 || w == 0;

}

void solve(){
    std::cin >> n;
    a.resize(n);
    byH.assign(n, 0);
    byW.assign(n, 0);

    ll S = 0, maxH = 0, maxW = 0;

    for(ll i = 0; i < n; i++) {
        std::cin >> a[i].first >> a[i].second;
        ll h = a[i].first, w = a[i].second;
        S += h * w;
        maxH = std::max(maxH, h);
        maxW = std::max(maxW, w);
        byH[i] = i, byW[i] = i;
    }

    std::sort(byH.begin(), byH.end(), [&](ll i, ll j){ return a[i].first > a[j].first; });
    std::sort(byW.begin(), byW.end(), [&](ll i, ll j){ return a[i].second > a[j].second; });

    std::vector<std::pair<ll, ll>> ans;
    if(S % maxH == 0){
        ll H = maxH, W = S / maxH;
        if(recur(W, H)) ans.push_back({H, W});
    }
    if(S % maxW == 0){
        ll H = S / maxW, W = maxW;
        if(recur(W, H)) ans.push_back({H, W});
    }

    if(ans.size() == 2 && ans[0] == ans[1]) ans.pop_back();

    std::cout << ans.size() << "\n";
    for(auto [H, W] : ans) std::cout << H << " " << W << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;
}