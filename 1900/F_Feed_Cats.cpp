#include <iostream>
#include <vector>

using ll = long long;

ll n, m;
std::vector<ll> cnt, L;
std::vector<ll> dp;

ll recur(ll i){
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];
    ll notTake = recur(i - 1);
    ll take = 0;
    if(cnt[i] > 0) take = cnt[i] + recur(L[i] - 1);

    return dp[i] = std::max(take, notTake);
}

void solve(){
    std::cin >> n >> m;
    std::vector<ll> diff(n + 2, 0), maxRight(n + 2, 0);
    
    cnt.assign(n + 1, 0);
    L.assign(n + 1, 0);
    dp.assign(n + 1, -1);

    for(ll i = 0; i < m; i++){
        ll l, r; std::cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
        maxRight[l] = std::max(maxRight[l], r);
    }

    ll left = 1, active = 0;
    for(ll i = 1; i <= n; i++){
        active += diff[i];
        cnt[i] = active;
        
        while(left <= i && maxRight[left] < i) left++;

        if(cnt[i] > 0) L[i] = left;
    }

    std::cout << recur(n) << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}