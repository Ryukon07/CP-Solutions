#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<ll> a(n), b(m);
    for(ll i = 0; i < n; i++) std::cin >> a[i];
    for(ll i = 0; i < m; i++) std::cin >> b[i];

    std::sort(b.rbegin(), b.rend());

    std::vector<ll> ans;

    ll i = 0, j = 0;
    while(i < n && j < m){
        if(b[j] >= a[i]) ans.push_back(b[j++]);
        else ans.push_back(a[i++]);
    }

    while(i < n) ans.push_back(a[i++]);
    while(j < m) ans.push_back(b[j++]);

    for(ll i = 0; i < ans.size(); i++){
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