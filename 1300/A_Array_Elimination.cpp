#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::vector<ll> freq(31, 0);
    for(ll i = 30; i >= 0; i--){
        for(ll x: a) if(((x >> i) & 1) == 1) freq[i]++;
    }

    ll g = 0;
    for(ll i = 0; i < 31; i++){
        if(freq[i] > 0) g = std::gcd(g, freq[i]);
    }

    if(g == 0){
        for(ll i = 1; i <= n; i++) std::cout << i << " ";
        std::cout << "\n";
        return;
    }

    std::vector<ll> divisors;
    for(ll i = 1; i * i <= g; i++){
        if(g % i == 0){
            divisors.push_back(i);
            if(i != g / i) divisors.push_back(g / i);
        }
    }

    std::sort(divisors.begin(), divisors.end());

    for(ll d: divisors){
        if(d <= n){
            std::cout << d << " ";
        }
    }
    std::cout << "\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}