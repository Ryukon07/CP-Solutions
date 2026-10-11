#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using ll = long long;
const ll INF = 1e18;

struct Node{
    ll maxVal, maxIdx, minVal, minIdx;
};

std::vector<Node> segTree;

Node merge(const Node &a, const Node &b){
    Node res;
    if(a.maxVal > b.maxVal){
        res.maxVal = a.maxVal;
        res.maxIdx = a.maxIdx;
    }else if(b.maxVal > a.maxVal){
        res.maxVal = b.maxVal;
        res.maxIdx = b.maxIdx;
    } else {
        res.maxVal = a.maxVal;
        res.maxIdx = std::min(a.maxIdx, b.maxIdx);
    }

    if(a.minVal < b.minVal){
        res.minVal = a.minVal;
        res.minIdx = a.minIdx;
    }else if(b.minVal < a.minVal){
        res.minVal = b.minVal;
        res.minIdx = b.minIdx;
    } else {
        res.minVal = a.minVal;
        res.minIdx = std::min(a.minIdx, b.minIdx);
    }

    return res;
}

void build(ll node, ll start, ll end, const std::vector<ll> &a){
    if(start == end){
        segTree[node] = {a[start], start, a[start], start};
    } else {
        ll mid = start + (end - start) / 2;
        build(2*node, start, mid, a);
        build(2*node+1, mid+1, end, a);
        segTree[node] = merge(segTree[2*node], segTree[2*node+1]);
    }
}

void update(ll node, ll start, ll end, ll idx){
    if(start == end){
        segTree[node] = {-INF, idx, INF, idx};
        return;
    }

    ll mid = start + (end - start) / 2;
    if (start <= idx && idx <= mid) update(2*node, start, mid, idx);
    else update(2*node+1, mid+1, end, idx);
    
    segTree[node] = merge(segTree[2*node], segTree[2*node+1]);
}

Node query(ll node, ll start, ll end, ll l, ll r){
    if(r < start || end < l) return {-INF, -1, INF, -1};
    if(l <= start && end <= r) return segTree[node];

    ll mid = start + (end - start) / 2;
    Node left = query(2*node, start, mid, l, r);
    Node right = query(2*node+1, mid+1, end, l, r);
    return merge(left, right);
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    std::vector<std::vector<ll>> pos(n + 1);
    std::vector<ll> lastPos(n + 1, -1);

    for(ll i = 0; i < n; ++i){
        std::cin >> a[i];
        pos[a[i]].push_back(i);
        lastPos[a[i]] = i;
    }

    std::set<ll> last;
    for(ll i = 1; i <= n; i++) if(lastPos[i] != -1) last.insert(lastPos[i]);

    segTree.assign(4 * n, {-INF, -1, INF, -1});
    build(1, 0, n - 1, a);

    ll L = 0;
    bool odd = true;
    std::vector<ll> ans;

    while(!last.empty()){
        ll R = *last.begin();

        Node best = query(1, 0, n - 1, L, R);
        ll pickedVal = odd ? best.maxVal : best.minVal;
        ll pickedIdx = odd ? best.maxIdx : best.minIdx;

        ans.push_back(pickedVal);

        L = pickedIdx + 1;

        last.erase(lastPos[pickedVal]);
        for(ll p: pos[pickedVal]) update(1, 0, n - 1, p);

        odd = !odd;
    }

    std::cout << ans.size() << "\n";
    for(ll x: ans) std::cout << x << " ";
    std::cout << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}