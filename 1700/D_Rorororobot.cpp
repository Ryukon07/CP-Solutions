#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
const ll MAX = 200005;
ll tree[4 * MAX];

void build(const std::vector<ll>& a, ll node, ll start, ll end){
    if(start == end){
        tree[node] = a[start];
    } else {
        ll mid = start + (end - start) / 2;
        build(a, 2 * node, start, mid);
        build(a, 2 * node + 1, mid + 1, end);
        tree[node] = std::max(tree[2 * node], tree[2 * node + 1]);
    }
}

ll query(ll node, ll start, ll end, ll l, ll r){
    if(r < start || end < l){
        return -1;
    }
    if(l <= start && end <= r){
        return tree[node];
    }
    ll mid = start + (end - start) / 2;
    ll leftMax = query(2 * node, start, mid, l, r);
    ll rightMax = query(2 * node + 1, mid + 1, end, l, r);
    return std::max(leftMax, rightMax);
}

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<ll> a(m + 1);
    for(ll i = 1; i <= m; i++) std::cin >> a[i];
    build(a, 1, 1, m);

    ll q; std::cin >> q;

    while(q--){
        ll xs, ys, xe, ye, k; std::cin >> xs >> ys >> xe >> ye >> k;


        if(std::abs(xe - xs) % k != 0 || std::abs(ye - ys) % k != 0){
            std::cout << "NO\n";
            continue;
        }

        ll l = std::min(ys, ye);
        ll r = std::max(ys, ye);
        ll maxReach = xs + ((n - xs) / k) * k;
        ll maxInRange = query(1, 1, m, l, r);

        if(maxReach > maxInRange) std::cout << "YES\n";
        else std::cout << "NO\n";

    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}