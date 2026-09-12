#include <iostream>
#include <vector>
#include <stack>

using ll = long long;
const ll INF = 1e18;

struct Node{
    ll min, max;
};

std::vector<Node> segtree;

void build(ll node, ll start, ll end, const std::vector<ll>& pref){
    if(start == end){
        segtree[node] = {pref[start], pref[start]};
        return;
    }

    ll mid = start + (end - start) / 2;
    build(2 * node, start, mid, pref);
    build(2 * node + 1, mid + 1, end, pref);

    segtree[node].min = std::min(segtree[2 * node].min, segtree[2 * node + 1].min);
    segtree[node].max = std::max(segtree[2 * node].max, segtree[2 * node + 1].max);
}

ll maxQuery(ll node, ll start, ll end, ll l, ll r, const std::vector<ll>& pref){
    if(r < start || end < l) return -INF;
    if(l <= start && end <= r) return segtree[node].max;

    ll mid = start + (end - start) / 2;
    ll leftMax = maxQuery(2 * node, start, mid, l, r, pref);
    ll rightMax = maxQuery(2 * node + 1, mid + 1, end, l, r, pref);

    return std::max(leftMax, rightMax);
}

ll minQuery(ll node, ll start, ll end, ll l, ll r, const std::vector<ll>& pref){
    if(r < start || end < l) return INF;
    if(l <= start && end <= r) return segtree[node].min;

    ll mid = start + (end - start) / 2;
    ll leftMin = minQuery(2 * node, start, mid, l, r, pref);
    ll rightMin = minQuery(2 * node + 1, mid + 1, end, l, r, pref);

    return std::min(leftMin, rightMin);
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n + 1);
    std::vector<ll> pref(n + 1, 0);
    for(ll i = 1; i <= n; i++){
        std::cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }

    std::vector<ll> x(n + 1), y(n + 1);
    std::stack<ll> st;

    for(ll i = 1; i <= n; i++){
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        x[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(ll i = n; i > 0; i--){
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        y[i] = st.empty() ? n + 1 : st.top();
        st.push(i);
    }

    segtree.assign(4 * (n + 1), {INF, -INF});
    build(1, 0, n, pref);

    for(ll i = 1; i <= n; i++){
        ll maxP = maxQuery(1, 0, n, i, y[i] - 1, a);
        ll minQ = minQuery(1, 0, n, x[i], i - 1, a);

        if(maxP - minQ > a[i]){
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}