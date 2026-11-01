#include <iostream>
#include <vector>

using ll = long long;
ll n, k;
std::vector<ll> parent;

bool check(ll mid){
    std::vector<ll> height(n + 1, 1);
    ll ops = 0;
    for(ll i = n; i >= 2; i--){
        if(height[i] == mid && parent[i] != 1){
            ops++;
            height[i] = 0;
        }
        ll p = parent[i];
        height[p] = std::max(height[p], height[i] + 1);
    }

    return ops <= k;

}

void solve(){
    std::cin >> n >> k;
    parent.assign(n + 1, 0);

    for(ll i = 2; i <= n; i++) std::cin >> parent[i];

    ll l = 1, r = n - 1;
    while(l < r){
        ll mid = l + (r - l) / 2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    std::cout << l << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;

}