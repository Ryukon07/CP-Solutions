#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
const ll INF = 1e18;

void solve(){
    ll n, k; std::cin >> n >> k;
    std::vector<ll> a(n);

    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::sort(a.begin(), a.end());

    ll min = a[0];
    for(ll i = 1; i < n; i++){
        min = std::min(min, a[i] - a[i - 1]);
    }

    if(k > 2) {std::cout << 0 << "\n"; return;}

    if(k == 1) std::cout << min << "\n";
    else {
        for(ll i = 0; i < n; i++){
            for(ll j = i + 1; j < n; j++){
                ll d = a[j] - a[i];
                auto it = std::lower_bound(a.begin(), a.end(), d);

                if(it != a.end()){
                    min = std::min(min, *it - d);
                }

                if(it != a.begin()){
                    --it;
                    min = std::min(min, d - *it);
                }
            }
        }
        std::cout << min << "\n";
    }
}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}