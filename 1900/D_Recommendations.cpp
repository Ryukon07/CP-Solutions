#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using ll = long long;

struct inter{
    ll l, r;
    int count;
    std::vector<int> id;
    ll L = -1;
    ll R = -1;
};

void solve() {
    int n;
    std::cin >> n;

    std::map<std::pair<ll, ll>, std::vector<int>> mp;
    for (int i = 0; i < n; i++) {
        ll l, r;
        std::cin >> l >> r;
        mp[{l, r}].push_back(i);
    }

    std::vector<inter> u;
    for (auto &p : mp) {
        u.push_back({p.first.first, p.first.second, (int)p.second.size(), p.second});
    }

    std::sort(u.begin(), u.end(), [](const inter &a, const inter &b) {
        if (a.l != b.l) return a.l < b.l;
        return a.r > b.r;
    });

    std::multiset<ll> set_r;
    for (auto &item : u) {
        if (item.count > 1) {
            item.R = item.r;
        } else {
            auto it = set_r.lower_bound(item.r);
            if (it != set_r.end()) {
                item.R = *it;
            }
        }
        set_r.insert(item.r);
    }

    std::sort(u.begin(), u.end(), [](const inter &a, const inter &b) {
        if (a.r != b.r) return a.r > b.r;
        return a.l < b.l;
    });

    std::multiset<ll> set_l;
    for (auto &item : u) {
        if (item.count > 1) {
            item.L = item.l;
        } else {
            auto it = set_l.upper_bound(item.l);
            if (it != set_l.begin()) {
                --it;
                item.L = *it;
            }
        }
        set_l.insert(item.l);
    }

    std::vector<ll> ans(n, 0);
    for (const auto &item : u) {
        ll res = 0;
        if (item.L != -1 && item.R != -1) {
            res = (item.l - item.L) + (item.R - item.r);
        }
        for (int id : item.id) {
            ans[id] = res;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << (i == n - 1 ? "" : "\n");
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}