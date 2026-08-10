#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> degree(n + 1, 0);
    for(ll i = 0; i < n - 1; ++i){
        ll u, v; std::cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    std::string s; std::cin >> s;

    ll c0 = 0, c1 = 0, cqleaf = 0, cqmid = 0;
    for(ll i = 2; i <= n; ++i){
        if(degree[i] == 1){
            if(s[i - 1] == '0') c0++;
            else if(s[i - 1] == '1') c1++;
            else cqleaf++;
        }
        else{
            if(s[i - 1] == '?') cqmid++;
        }
    }

    if(s[0] == '0') std::cout << c1 + (cqleaf + 1) / 2 << std::endl;
    else if(s[0] == '1') std::cout << c0 + (cqleaf + 1) / 2 << std::endl;
    else{
        if(c0 != c1) std::cout << std::max(c0, c1) + cqleaf / 2 << std::endl;
        else{
            if(cqleaf % 2) std::cout << c0 + (cqleaf/2) + (cqmid % 2)  << std::endl;
            else std::cout << c0 + cqleaf / 2 << std::endl;
        }
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
}