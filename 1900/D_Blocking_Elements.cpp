#include <iostream>
#include <vector>
#include <deque>

using ll = long long;

bool check(std::vector<ll>& a, std::vector<ll>& pref, ll mid){
    ll n = a.size();
    std::vector<ll> dp(n + 1, 0);
    std::deque<ll> dq;
    dq.push_back(0);

    for(ll i = 1; i <= n; i++){
        while(!dq.empty() && pref[i-1] - pref[dq.front()] > mid) dq.pop_front();
        dp[i] = a[i-1] + dp[dq.front()];
        while(!dq.empty() && dp[i] <= dp[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }

    while(!dq.empty() && pref[n] - pref[dq.front()] > mid) dq.pop_front();
    return !dq.empty() && dp[dq.front()] <= mid;
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::vector<ll> pref(n + 1, 0);
    for(ll i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

    ll low = 0, high = pref[n];

    while(low < high){
        ll mid = low + (high - low) / 2;
        if(check(a, pref, mid)) high = mid;
        else low = mid + 1;
    }
    
    std::cout << low << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}