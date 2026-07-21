#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

struct interval{
    ll l, r, idx;
};

void solve(){
    ll n; std::cin >> n;
    std::vector<interval> a(n);
    for(ll i = 0; i < n; ++i){
        std::cin >> a[i].l >> a[i].r;
        a[i].idx = i;
    }

    std::sort(a.begin(), a.end(), [](const interval &x, const interval &y){
        return x.l < y.l;
    });

    std::vector<ll> ans(n, 0);
    ans[a[0].idx] = 1;

    ll mx1 = a[0].r;
    ll idx = -1;
    for(ll i = 1; i < n; i++){
        if(a[i].l > mx1){
            idx = i;
            break;
        }
        mx1 = std::max(mx1, a[i].r);
    }

    if(idx == -1){
        std::cout << "-1\n";
        return;
    }

    for(ll i = 0; i < idx; i++){
        ans[a[i].idx] = 1;
    }
    for(ll i = idx; i < n; i++){
        ans[a[i].idx] = 2;
    }

    for(ll i = 0; i < n; i++){
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;

}