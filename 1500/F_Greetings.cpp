#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

ll query(std::vector<ll> &tree, ll idx){
    ll sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

void add(std::vector<ll> &tree, ll idx, ll val){
    while(idx < tree.size()){
        tree[idx] += val;
        idx += idx & -idx;
    }
}

void solve(){
    ll n; std::cin >> n;
    std::vector<std::pair<ll, ll>> ab(n);
    for(auto &x : ab) std::cin >> x.first >> x.second;

    std::sort(ab.begin(), ab.end());

    std::vector<ll> b(n), rank(n);
    std::vector<ll> tree(n + 1, 0);

    for(ll i = 0; i < n; i++) b[i] = ab[i].second;

    std::vector<ll> sorted_b = b;
    std::sort(sorted_b.begin(), sorted_b.end());

    for(ll i = 0; i < n; i++) {
        rank[i] = std::lower_bound(sorted_b.begin(), sorted_b.end(), b[i]) - sorted_b.begin() + 1;
    }

    ll seen = 0, ans = 0;
    for(ll i = 0; i < n; i++){
        ll r = rank[i];
        
        ll tmp = seen - query(tree, r);
        ans += tmp;
        seen++;
        ll idx = r;
        add(tree, idx, 1);
    }

    std::cout << ans << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}