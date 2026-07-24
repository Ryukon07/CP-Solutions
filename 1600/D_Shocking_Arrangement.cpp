#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::sort(a.begin(), a.end());

    if(a[0] == 0 && a[n - 1] == 0){
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";

    std::vector<ll> ans;
    ll left = 0, right = n - 1;
    ll sum = 0;
    while(left <= right){
        if(sum < 0){
            sum += a[right];
            ans.push_back(a[right]);
            right--;
        } else {
            sum += a[left];
            ans.push_back(a[left]);
            left++;
        }
    }

    for(ll i = 0; i < n; i++){
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;

}