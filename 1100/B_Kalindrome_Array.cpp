#include <iostream>
#include <vector>

using ll = long long;

bool check(std::vector<ll>& a, ll x){
    ll n = a.size();
    std::vector<ll> b;
    for(ll i = 0; i < n; i++){
        if(a[i] != x) b.push_back(a[i]);
    }

    ll m = b.size();
    for(ll i = 0; i < m / 2; i++){
        if(b[i] != b[m - 1 - i]) return false;
    }
    return true;
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];

    for(ll i = 0; i < n / 2; i++){
        if(a[i] != a[n - 1 - i]){
            if(check(a, a[i])){
                std::cout << "YES\n";
                return;
            }
            if(check(a, a[n - 1 - i])){
                std::cout << "YES\n";
                return;
            }
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}