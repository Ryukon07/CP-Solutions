#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    bool hasZero = false, allSame = true;
    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        if(a[i] % 2 != 0) a[i] += a[i] % 10;
        if(a[i] % 10 == 0) hasZero = true;
        if(i > 0 && a[i] != a[i-1]) allSame = false;
    }

    if(allSame){
        std::cout << "Yes\n";
        return;
    }else if(hasZero){
        std::cout << "No\n";
        return;
    }else{
        for(ll i = 0; i < n; i++){
            while(a[i] % 10 != 2) a[i] += a[i] % 10;
        }
        bool allSameMod20 = true;
        for(ll i = 1; i < n; i++){
            if(a[i] % 20 != a[i-1] % 20){
                allSameMod20 = false;
                break;
            }
        }
        if(allSameMod20) std::cout << "Yes\n";
        else std::cout << "No\n";
    }

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}