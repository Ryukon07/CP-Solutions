#include <iostream>
#include <vector>
#include <set>

using ll = long long;

void solve(){
    int n; std::cin >> n;
    std::set<ll> a;
    for(int i = 0; i < n; i++){
        ll x; std::cin >> x;
        a.insert(x);
    }

    if(a.size() < n) std::cout << "YES\n";
    else std::cout << "NO\n";
}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}