#include <iostream>
#include <vector>
#include <string>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];
    
    std::string s; std::cin >> s;
    
    std::vector<ll> prefXor(n, 0);
    ll xor0 = 0, xor1 = 0;

    prefXor[0] = a[0];
    if(s[0] == '0') xor0 ^= a[0];
    else xor1 ^= a[0];

    for(ll i = 1; i < n; i++){
        prefXor[i] = prefXor[i-1] ^ a[i];
        if(s[i] == '0') xor0 ^= a[i];
        else xor1 ^= a[i];
    }

    ll q; std::cin >> q;
    while(q--){
        ll tp; std::cin >> tp;
        if(tp == 2){
            ll g; std::cin >> g;
            if(g == 0) std::cout << xor0 << " ";
            else std::cout << xor1 << " ";
        }else{
            ll l, r; std::cin >> l >> r;
            l--; r--;
            ll rem = prefXor[r] ^ (l > 0 ? prefXor[l-1] : 0);
            xor0 ^= rem;
            xor1 ^= rem;
        }
    }
    std::cout << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}