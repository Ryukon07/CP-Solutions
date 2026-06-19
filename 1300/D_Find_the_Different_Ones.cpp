#include <iostream>
#include <vector>
#include <map>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    
    std::vector<ll> lastDiff(n, -1);

    for(ll i = 0; i < n; i++) std::cin >> a[i];

    ll ptr = -1;
    for(ll i = 1; i < n; i++){
        if(a[i] != a[i-1]){
            ptr = i-1;
        }
        lastDiff[i] = ptr;
    }


    ll q; std::cin >> q;
    while(q--){
        ll l, r; std::cin >> l >> r;
        if(lastDiff[r-1] >= l-1){
            std::cout << r << " " << lastDiff[r-1]+1 << "\n";
        }else{
            std::cout << "-1 -1\n";
        }
    }

}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}