#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n, q; std::cin >> n >> q;
    std::vector<ll> a(n + 1), prefixXOR(n + 1, 0), cnt(n + 1, 0);
    std::vector<std::pair<ll, ll>> positions[2];
    positions[0].push_back({0, 0});

    for(ll i = 1; i <= n; i++){
        std::cin >> a[i];
        prefixXOR[i] = prefixXOR[i - 1] ^ a[i];
        cnt[i] = cnt[i - 1] + (a[i] != 0);
        positions[i % 2].push_back({prefixXOR[i], i});
    }

    std::sort(positions[0].begin(), positions[0].end());
    std::sort(positions[1].begin(), positions[1].end());

    while(q--){
        ll l, r; std::cin >> l >> r;
        ll length = r - l + 1;

        // If all elements are zero
        if(cnt[r] - cnt[l - 1] == 0){
            std::cout << "0\n";
            continue;
        }

        // if XOR is not zero
        if((prefixXOR[r] ^ prefixXOR[l - 1]) != 0){
            std::cout << "-1\n";
            continue;
        }

        // if lenth is odd
        if(length % 2 == 1){
            std::cout << "1\n";
            continue;
        }
        
        // length even, but first or last element = 0
        if(a[l] == 0 || a[r] == 0){
            std::cout << "1\n";
            continue;
        }

        // even length, find some index
        auto &pos = positions[l % 2];
        auto it = std::lower_bound(pos.begin(), pos.end(), std::make_pair(prefixXOR[l - 1], l));

        if(it != pos.end() && it->first == prefixXOR[l - 1] && it->second < r){
            std::cout << "2\n";
        } else {
            std::cout << "-1\n";
        }
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}