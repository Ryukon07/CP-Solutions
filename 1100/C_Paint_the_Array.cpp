#include <iostream>
#include <vector>
#include <numeric>

using ll = long long;

void solve(){
    int n; std::cin >> n;
    std::vector<ll> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];

    ll gcdOdd = 0, gcdEven = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) gcdOdd = std::gcd(gcdOdd, a[i]);
        else gcdEven = std::gcd(gcdEven, a[i]);
    }

    bool flag = true;
    for(int i = 1; i < n; i += 2) if(a[i] % gcdOdd == 0){flag = false; break;}

    if(flag){
        std::cout << gcdOdd << "\n";
        return;
    }

    flag = true;
    for(int i = 0; i < n; i+=2) if(a[i] % gcdEven == 0){flag = false; break;}

    if(flag){std::cout << gcdEven << "\n";}
    else{std::cout << 0 << "\n";}

}

int main(){
    int t; std::cin >> t;
    while(t--){
        solve();
    }
}