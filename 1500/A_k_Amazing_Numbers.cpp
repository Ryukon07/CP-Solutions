#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::map<ll, std::vector<ll>> gaps;
    for(ll i = 0; i < n; i++){
        gaps[a[i]].push_back(i);
    }

    std::vector<ll> can(n + 1, -1);

    for(auto &[val, indices]: gaps){
        ll max_gap = indices[0] + 1;
        for(ll i = 1; i < indices.size(); i++){
            max_gap = std::max(max_gap, indices[i] - indices[i - 1]);
        }
        max_gap = std::max(max_gap, n - indices.back());

        if(can[max_gap] == -1 || val < can[max_gap]){
            can[max_gap] = val;
        }

    }

    ll best = -1;
    for(ll i = 1; i <= n; i++){
        if(can[i] != -1){
            if(best == -1 || can[i] < best){
                best = can[i];
            }
        }
        std::cout << best << " ";
    }

    std::cout << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}