#include <iostream>
#include <vector>

using ll = long long;

std::vector<ll> getDivisiors(ll n){
    std::vector<ll> divisors;
    for(ll i = 1; i * i <= n; ++i){
        if(n % i == 0){
            divisors.push_back(i);
            if(i != n / i) divisors.push_back(n / i);
        }
    }
    return divisors;
}

void solve(){
    ll a, b, c, d; std::cin >> a >> b >> c >> d;
    std::vector<ll> divisorsA = getDivisiors(a), divisorsB = getDivisiors(b);

    for(ll p: divisorsA){
        for(ll q: divisorsB){
            ll g = p * q;
            ll h = (a / p) * (b / q);

            ll x = (c / g) * g;
            ll y = (d / h) * h;

            if(x > a && y > b){
                std::cout << x << " " << y << "\n";
                return;
            }
        }
    }

    std::cout << "-1 -1\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;    
    while(t--) solve();
    return 0;

}