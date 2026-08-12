#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

ll swaps(std::vector<ll> &v){
    ll ans = 0;
    for(ll i = 0; i < v.size(); i++){
        while(v[i] != i){
            std::swap(v[i], v[v[i]]);
            ans++;
        }
    }
    return ans;
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n), b(n);

    for(ll i = 0; i < n; i++) std::cin >> a[i];
    for(ll i = 0; i < n; i++) std::cin >> b[i];

    std::vector<ll> tempa = a, tempb = b;
    std::sort(tempa.begin(), tempa.end());
    std::sort(tempb.begin(), tempb.end());

    if(tempa != tempb){
        std::cout << "NO\n";
        return;
    }

    std::vector<ll> mpa(n), mpb(n);
    for(ll i = 0; i < n; i++){
        mpa[i] = std::lower_bound(tempa.begin(), tempa.end(), a[i]) - tempa.begin();
        mpb[i] = std::lower_bound(tempb.begin(), tempb.end(), b[i]) - tempb.begin();
    }

    ll swapa = swaps(mpa), swapb = swaps(mpb);

    if(swapa % 2 == swapb % 2) std::cout << "YES\n";
    else std::cout << "NO\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;

}