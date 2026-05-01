#include <iostream>

using ll = long long;

void solve(){
    ll a, b; std::cin >> a >> b;
    ll ans = 1e18;

    for(ll i = 0; i < 30; i++){
        ll ops = i;
        ll tempB = b + ops;
        if(tempB == 1) continue;
        ll tempA = a;
        while(tempA > 0){
            tempA /= tempB;
            ops++;
        }
        ans = std::min(ans, ops);
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