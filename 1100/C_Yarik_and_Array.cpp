#include <iostream>
#include <vector>

using ll = long long;

void modifiedKadane(const std::vector<ll>& a, const ll n){
    ll ans = -1e18, sum = 0;
    ll i = 0, j = 0;
    while(j < n){
        if(sum < 0) sum = 0, i = j;
        if(i < j){
            if((a[j] ^ a[j - 1]) & 1) sum += a[j];
            else sum = a[j], i = j;
        }else{
            sum = a[j];
        }
        ans = std::max(ans, sum);
        j++;
    }
    std::cout << ans << "\n";
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    modifiedKadane(a, n);

}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}