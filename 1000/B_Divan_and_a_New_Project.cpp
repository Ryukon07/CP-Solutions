#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<std::pair<ll, ll>> a(n);
    for(ll i = 0; i < n; i++){
        ll x; std::cin >> x;
        a[i] = {x, i + 1};
    }

    std::sort(a.begin(), a.end(), [](const std::pair<ll, ll> &p1, const std::pair<ll, ll> &p2){
        return p1.first > p2.first;
    }); 

    ll total = 0;

    std::vector<ll> ans(n + 1);
    if(n % 2 != 0){
        ans[0] = 0;
        ll tracker = 1;
        for(ll i = 0; i < n - 1; i += 2){
            ans[a[i].second] = tracker;
            ans[a[i + 1].second] = -tracker;
            total += (a[i].first + a[i + 1].first) * tracker;
            tracker++;
        }

        total += a[n - 1].first * tracker;
        ans[a[n -1].second] = tracker;

    }else{
        ans[0] = 0;
        ll tracker = 1;
        for(ll i = 0; i < n; i += 2){
            ans[a[i].second] = tracker;
            ans[a[i + 1].second] = -tracker;
            total += (a[i].first + a[i + 1].first) * tracker;
            tracker++;
        }
    }

    std::cout << total * 2 << "\n";
    for(ll i = 0; i <= n; i++){
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";
}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}