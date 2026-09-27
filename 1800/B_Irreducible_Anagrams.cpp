#include <iostream>
#include <vector>

using ll = long long;
const ll MAX = 200005;
ll tree[4 * MAX];
std::string s;

void build(ll node, ll start, ll end){
    if(start == end){
        tree[node] = (1 << (s[start - 1] - 'a'));
        return;
    }else{
        ll mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] | tree[2 * node + 1];
    }
}

ll query(ll node, ll start, ll end, ll l, ll r){
    if(r < start || end < l) return 0;
    if(l <= start && end <= r) return tree[node];

    ll mid = start + (end - start) / 2;
    ll p1 = query(2 * node, start, mid, l, r);
    ll p2 = query(2 * node + 1, mid + 1, end, l, r);
    return p1 | p2;
}

void solve(){
    std::cin >> s;
    ll n = s.size();

    build(1, 1, n);

    ll q; std::cin >> q;
    while(q--){
        ll l, r; std::cin >> l >> r;
        if(l == r || s[l-1] != s[r-1]) std::cout << "Yes\n";
        else{
            ll res = query(1, 1, n, l, r);
            if(__builtin_popcount(res) > 2) std::cout << "Yes\n";
            else std::cout << "No\n";
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

}