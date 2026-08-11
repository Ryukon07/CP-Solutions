#include <iostream>
#include <vector>

using ll = long long;

ll check(ll a, ll b){
    if(a > b) std::swap(a, b);

    std::cout << "? " << a << " " << b << std::endl;
    ll x; std::cin >> x;

    if(x == a * b) return 0;
    else if(x == a * (b + 1)) return 1;
    else return 2;

}

void solve(){

    ll l = 2, r = 1000;
    while(l < r){
        ll midl = l + (r - l) / 3;
        ll midr = r - (r - l) / 3;

        ll res = check(midl, midr);

        if(res == 0){
            l  = midr + 1;
        }else if(res == 1){
            l = midl + 1;
            r = midr;
        }else if(res == 2){
            r = midl;
        }
    }

    std::cout << "! " << l << std::endl;

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
}