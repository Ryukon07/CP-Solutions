#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;

    ll low = 1, high = n;
    while(low < high){
        ll mid = low + (high - low) / 2;

        std::cout << "? " << low << " " << mid << std::endl;
        ll cnt = 0;
        for(ll i = 0; i < mid - low + 1; i++){
            ll x; std::cin >> x;
            if(x >= low && x <= mid) cnt++;
        }

        if(cnt % 2 != 0){
            high = mid;
        }else{
            low = mid + 1;
        }
    }

    std::cout << "! " << low << std::endl;

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}