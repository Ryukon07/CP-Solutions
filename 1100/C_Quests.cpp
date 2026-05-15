#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, k; std::cin >> n >> k; //n = Number of quests, k = maximum number of quests that can be completed
    std::vector<ll> a(n), b(n); //a = first time completion xp earned, b = susbsequent time completion xp earned
    std::vector<ll> prefixSumOfA(n), maximumB(n);
    
    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        prefixSumOfA[i] = a[i] + (i > 0 ? prefixSumOfA[i - 1] : 0);
    }

    ll maxB = -1;
    for(ll i = 0; i < n; i++){
        std::cin >> b[i];
        maxB = std::max(maxB, b[i]);
        maximumB[i] = maxB;
    }
    
    ll ans = 0;
    for(ll i = 0; i < std::min(n, k); i++){
        ll currentXP = prefixSumOfA[i];
        ll rem = k - (i + 1);
        currentXP += rem * maximumB[i];
        ans = std::max(ans, currentXP);
    }

    std::cout << ans << "\n";


}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}