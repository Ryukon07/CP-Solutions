#include <iostream>
#include <vector>

using ll = long long;

ll n, k;
std::vector<ll> a, cold, hot;
std::vector<std::vector<ll>> dp;

ll recur(ll last1, ll last2){
    ll i = std::max(last1, last2) + 1;

    if(i == n) return 0;
    if(dp[last1 + 1][last2 + 1] != -1) return dp[last1 + 1][last2 + 1];

    ll cost1 = cold[a[i] - 1];
    if(last1 != -1 && a[last1] == a[i]) cost1 = hot[a[i] - 1];

    ll cost2 = cold[a[i] - 1];
    if(last2 != -1 && a[last2] == a[i]) cost2 = hot[a[i] - 1];

    ll op1 = cost1 + recur(i, last2);
    ll op2 = cost2 + recur(last1, i);

    return dp[last1 + 1][last2 + 1] = std::min(op1, op2);
}

void solve(){
    std::cin >> n >> k;
    a.resize(n);
    cold.resize(k);
    hot.resize(k);

    for(ll i = 0; i < n; i++) std::cin >> a[i];
    for(ll i = 0; i < k; i++) std::cin >> cold[i];
    for(ll i = 0; i < k; i++) std::cin >> hot[i];

    dp.assign(n + 1, std::vector<ll>(n + 1, -1));
    std::cout << recur(-1, -1) << "\n";

}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}