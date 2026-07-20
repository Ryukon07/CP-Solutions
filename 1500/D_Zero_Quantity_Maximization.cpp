#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n), b(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];
    for(ll i = 0; i < n; i++) std::cin >> b[i];


    std::map<std::pair<ll, ll>, ll> freq;
    ll max = 0;

    ll zero = 0;
    for(ll i = 0; i < n; i++){
        if(a[i] == 0){
            if(b[i] == 0) zero++;
        }else{
            ll num = -1 * b[i];
            ll den = a[i];

            ll g = std::gcd(num, den);
            num /= g; den /= g;

            if(den < 0) {
                num = -num; den = -den;
            }

            freq[{num, den}]++;
            if(freq[{num, den}] > max) max = freq[{num, den}];
        }
    }

    std::cout << max + zero << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}