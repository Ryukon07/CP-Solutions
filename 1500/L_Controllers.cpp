#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::string s; std::cin >> s;

    ll plus = 0, minus = 0;
    for(auto c : s){
        if(c == '+') plus++;
        else minus++;
    }

    ll q; std::cin >> q;
    while(q--){
        ll x, y; std::cin >> x >> y;
        if(plus == minus) std::cout << "YES\n";
        else if(x == y) std::cout << "NO\n";
        else{
            ll num = (minus - plus) * y, den = x - y;
            if(num % den != 0) std::cout << "NO\n";
            else{
                ll val = num / den;

                ll high = std::min(minus, plus - val), low = std::max(0LL, -val);
                if(low <= high) std::cout << "YES\n";
                else std::cout << "NO\n";

            }
        }
    }

}

int main(){
   solve();
   return 0;
}