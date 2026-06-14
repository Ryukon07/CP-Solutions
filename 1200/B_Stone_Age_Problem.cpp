#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, q; std::cin >> n >> q;
    std::vector<ll> a(n);
    ll sum = 0;
    for(ll i = 0; i < n; i++) {std::cin >> a[i]; sum += a[i];}

    ll allTime = 0, allVal = 0;
    std::vector<ll> time(n, 0);

    for(ll t = 1; t <= q; t++){
        ll type; std::cin >> type;
        if(type == 1){
            ll i, x; std::cin >> i >> x; i--;
            ll cur = (time[i] >= allTime) ? a[i] : allVal;
            sum += (x - cur);
            a[i] = x; time[i] = t;
        }else{
            ll x; std::cin >> x;
            allVal = x; allTime = t;
            sum = x * n;
        }
        std::cout << sum << "\n";
    }

}

int main(){
    solve();
}