#include <iostream>
#include <vector>

using ll = long long;
const ll INF = 1e18;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    ll ans = 0, last1 = INF, last2 = INF;
    for(ll i = 0; i < n; i++){
        if(last1 >= a[i] && last2 >= a[i]) (last1 <= last2 ? last1 : last2) = a[i];
        else if(last1 >= a[i]) last1 = a[i];
        else if(last2 >= a[i]) last2 = a[i];
        else{
            ans++;
            (last1 <= last2 ? last1 : last2) = a[i];
        }
    }

    std::cout << ans << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}