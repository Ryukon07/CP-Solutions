#include <iostream>
#include <vector>

using ll = long long;

ll ask(ll i, ll j){
    std::cout << "? " << i << " " << j << std::endl;
    ll x; std::cin >> x;
    if(x == 0) exit(0);
    return x;
}

void solve(){

    ll p11 = ask(1, 1);
    ll p12 = ask(1, 2);
    ll p34 = ask(3, 4);
    ll p35 = ask(3, 5);

    ll ans[7] = {0, 0, 0, 0, 0, 0, 0};
    ll v[6] = {4, 8, 15, 16, 23, 42};

    for(auto x: v) if(x * x == p11) ans[1] = x;
    ans[2] = p12 / ans[1];

    auto sp = [&](ll q){ for(auto y: v) if(q == y) return true; return false; };

    for(auto x: v) if(x != ans[1] && x != ans[2] && p34 % x == 0 && p35 % x == 0 && sp(p34/x) && sp(p35/x) && p34/x != x && p35/x != x) ans[3] = x;
    ans[4] = p34 / ans[3];
    ans[5] = p35 / ans[3];

    for(auto x: v) if(x != ans[1] && x != ans[2] && x != ans[3] && x != ans[4] && x != ans[5]) ans[6] = x;

    std::cout << "! ";
    for(ll i = 1; i <= 6; i++) std::cout << ans[i] << " ";
    std::cout << std::endl;

}

int main(){
    solve();
    return 0;
}