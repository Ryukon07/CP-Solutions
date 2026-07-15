#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, a, b; std::cin >> n >> a >> b;
    std::vector<ll> arr(n + 1);
    for(ll i = 1; i <= n; i++) std::cin >> arr[i];
    arr[0] = 0;

    std::vector<ll> prefSum(n + 1, 0);
    prefSum[0] = 0;
    for(ll i = 1; i <= n; i++) prefSum[i] = prefSum[i - 1] + arr[i];

    ll ans = b * prefSum[n];

    for(ll i = 1; i <= n; i++){
        ll cap = a * arr[i];
        ll cost = b * arr[i];

        ll rem = prefSum[n] - prefSum[i];
        ll count = n - i;
        ll cost2 = b * (rem - count * arr[i]);

        ll curr = cap + cost + cost2;
        ans = std::min(ans, curr);
    }

    std::cout << ans << "\n";


}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}