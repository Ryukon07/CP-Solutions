#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <functional>

using ll = long long;

void solve(){
    ll x, k; std::cin >> x >> k;
    std::vector<std::vector<ll>> arr(k);

    for(ll i = 0; i < k; i++){
        ll n; std::cin >> n;
        arr[i].resize(n);
        for(ll j = 0; j < n; j++) std::cin >> arr[i][j];
    }

    std::vector<std::vector<std::pair<ll, ll>>> after(k);
    for(ll i = 0; i < k; i++){
        ll sum = 0, minSum = 0;
        for(ll a: arr[i]){
            sum += a;
            minSum = std::min(minSum, sum);

            if(sum > 0){
                after[i].emplace_back(-minSum, sum);
                sum = 0;
                minSum = 0;
            }
        }
    }

    std::priority_queue<std::tuple<ll, ll, ll>, std::vector<std::tuple<ll, ll, ll>>, std::greater<std::tuple<ll, ll, ll>>> pq;
    std::vector<ll> pos(k, 0);

    for(ll i = 0; i < k; i++){
        if(!after[i].empty()){
            pq.emplace(after[i][0].first, after[i][0].second, i);
        }
    }

    while(!pq.empty()){
        auto t = pq.top();
        ll need = std::get<0>(t);
        ll profit = std::get<1>(t);
        ll idx = std::get<2>(t);

        if(x < need) break;
        pq.pop();
        x += profit;
        pos[idx]++;

        if(pos[idx] < after[idx].size()){
            ll n = after[idx][pos[idx]].first;
            ll p = after[idx][pos[idx]].second;
            pq.emplace(n, p, idx);
        }
    }

    std::cout << x << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}