#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    ll total = 0;
    for(auto &x : a) {
        std::cin >> x;
        total += x;
    }

    ll presses = (total + 1) / 2, rem = total - presses;
    std::sort(a.begin(), a.end(), std::greater<ll>());

    for(ll i = 0; i < n; i++){
        if(rem > 0){
            if(a[i] <= rem){
                rem -= a[i];
                presses++;
            }else{
                rem = 0;
                presses++;
            }
        }else{
            break;
        }
    }

    std::cout << presses << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}