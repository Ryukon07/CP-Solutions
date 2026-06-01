#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::vector<ll> b;
    for(ll i = 0; i < n; i++){
        if(b.empty() || b.back() != a[i]) b.push_back(a[i]);
    }

    ll m = b.size();
    if(m == 1){
        std::cout << 1 << "\n";
        return;
    }

    ll ans = 2;
    for(ll i = 1; i < m - 1; i++){
        if(b[i] > b[i - 1] && b[i] > b[i + 1]) ans++;
        else if(b[i] < b[i - 1] && b[i] < b[i + 1]) ans++;
    }

    std::cout << ans << "\n";

}

int main(){

    ll t; std::cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}