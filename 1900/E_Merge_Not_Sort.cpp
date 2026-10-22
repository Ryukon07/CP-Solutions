#include <iostream>
#include <vector>

using ll = long long;
ll n;
std::vector<ll> arr, idx, size;
std::vector<std::vector<int>> dp;

bool recur(ll i, ll sum) {
    if (sum > n) return false;
    if (i == size.size()) return sum == n;
    if (dp[i][sum] != -1) return dp[i][sum];

    if (recur(i + 1, sum + size[i])) return dp[i][sum] = 1;
    if (recur(i + 1, sum)) return dp[i][sum] = 1;

    return dp[i][sum] = 0;
}

void solve(){
    std::cin >> n;
    arr.resize(2 * n);
    for(ll i = 0; i < 2 * n; i++) std::cin >> arr[i];

    ll mx = 0;

    for(ll i = 0; i < 2 * n; i++){
        if(arr[i] > mx){
            mx = arr[i];
            idx.push_back(i);
        }
    }

    for (ll i = 0; i < idx.size(); i++) {
        ll end = (i + 1 < idx.size()) ? idx[i + 1] : 2 * n;
        size.push_back(end - idx[i]);
    }

    dp.assign(size.size() + 1, std::vector<int>(n + 1, -1));

    if(!recur(0, 0)){
        std::cout << -1 << "\n";
        return;
    }

    std::vector<ll> a, b;
    ll sum = 0;

    for(ll i = 0; i < size.size(); i++){
        bool take = (sum + size[i] <= n && recur(i + 1, sum + size[i]));
        for(ll j = idx[i]; j < idx[i] + size[i]; j++){
            if(take) a.push_back(arr[j]);
            else b.push_back(arr[j]);
        }

        if(take) sum += size[i];
    }

    for (ll x : a) std::cout << x << " ";
    std::cout << "\n";

    for (ll x : b) std::cout << x << " ";
    std::cout << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}