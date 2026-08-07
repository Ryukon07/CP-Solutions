#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using ll = long long;

void segmentTree(std::vector<ll> &arr, std::vector<ll> &tree, ll n, ll node, ll start, ll end){

    if(start == end){
        tree[node] = arr[start];
        return;
    }
    ll mid = start + (end - start) / 2;
    segmentTree(arr, tree, n, 2*node, start, mid);
    segmentTree(arr, tree, n, 2*node+1, mid+1, end);

    tree[node] = std::gcd(tree[2*node], tree[2*node+1]);
}

ll query(std::vector<ll> &tree, ll node, ll start, ll end, ll l, ll r){
    if(r < start || end < l) return 0;
    if(l <= start && end <= r) return tree[node];

    ll mid = start + (end - start) / 2;
    ll left_gcd = query(tree, 2*node, start, mid, l, r);
    ll right_gcd = query(tree, 2*node+1, mid+1, end, l, r);
    return std::gcd(left_gcd, right_gcd);
}

void solve(){
    ll n, q; std::cin >> n >> q;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    if(n == 1){
        while(q--){
            ll l, r; std::cin >> l >> r;
            std::cout << 0 << " ";
        }
        std::cout << "\n";
        return;
    }

    std::vector<ll> diff(n-1);
    for(ll i = 0; i < n-1; i++) diff[i] = std::abs(a[i+1] - a[i]);

    std::vector<ll> tree(4*(n-1));
    segmentTree(diff, tree, n-1, 1, 0, n-2);

    while(q--){
        ll l, r; std::cin >> l >> r;
        if(l == r) std::cout << 0 << " ";
        else{
            ll g = query(tree, 1, 0, n-2, l-1, r-2);
            std::cout << g << " ";
        }
    }
    std::cout << "\n";


}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}