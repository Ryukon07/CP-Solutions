#include <iostream>
#include <vector>
#include <map>

using ll = long long;

void solve(){
    ll n, k; std::cin >> n >> k;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::map<ll, bool> mp;
    for(auto i : a) mp[i] = true;
    for(ll i = 0; i < n; i++){
        if(mp.find(a[i] - k) != mp.end()){
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
}

int main(){
    ll t;std::cin >> t;
    while(t--){
        solve();
    }
}