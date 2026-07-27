#include <iostream>

using ll = long long;

ll check(ll n, ll m){
    ll res = 0;

    for(ll i = 62; i >= 0; --i){
        ll bit_n = (n >> i) & 1;
        ll bit_m = (m >> i) & 1;

        if(bit_n == bit_m){
            res |= (bit_n << i);
        }else{
            break;
        }
    }

    return res;

}

void solve(){
    ll n, x; std::cin >> n >> x;

    if(n == x) {std::cout << n << "\n"; return;}
    if(x > n || (n & x) != x) {std::cout << "-1\n"; return;}

    ll k = -1;
    for(ll i = 62; i >= 0; --i){
        if(((n >> i) & 1) != ((x >> i) & 1)){
            k = i;
            break;
        }
    }

    ll mask = ~((1LL << (k + 1)) - 1);
    ll m = (n & mask) + (1LL << (k + 1));

    if(check(n, m) == x){
        std::cout << m << "\n";
    }else{
        std::cout << "-1\n";
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}