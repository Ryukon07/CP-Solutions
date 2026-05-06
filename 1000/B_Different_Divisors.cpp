#include <iostream>
#include <vector>

using ll = long long;

void solve(std::vector<ll> primes){
    ll d; std::cin >> d;

    ll x = -1; 
    for(ll i = 0; i < primes.size(); i++){
        if(primes[i] >= 1 + d){
            x = primes[i];
            break;
        }
    }

    ll y = -1;
    for(ll i = 0; i < primes.size(); i++){
        if(primes[i] >= x + d){
            y = primes[i];
            break;
        }
    }

    ll ans = std::min(x * x * x, x * y);
    std::cout << ans << std::endl;


}

int main(){

    std::vector<ll> primes;
    for(ll i = 2; i <= 100000; i++){
        bool is_prime = true;
        for(ll j = 2; j * j <= i; j++){
            if(i % j == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            primes.push_back(i);
        }
    }

    int t; std::cin >> t;
    while(t--){
        solve(primes);
    }

    return 0;
}