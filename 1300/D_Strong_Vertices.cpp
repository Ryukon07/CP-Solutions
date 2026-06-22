#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n), b(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];
    for(ll i = 0; i < n; i++) std::cin >> b[i];

    std::vector<std::pair<ll, ll>> pairs(n);
    for(ll i = 0; i < n; i++){
        pairs[i] = {a[i] - b[i], i + 1};
    }

    std::sort(pairs.rbegin(), pairs.rend());

    std::vector<ll> strongVertices;
    strongVertices.push_back(pairs[0].second);

    ll i = 1;
    while(i < n && pairs[i].first == pairs[0].first){
        strongVertices.push_back(pairs[i].second);
        i++;
    }

    std::sort(strongVertices.begin(), strongVertices.end());
    std::cout << strongVertices.size() << "\n";
    for(ll v: strongVertices) std::cout << v << " ";
    std::cout << "\n";

}

int main(){

    ll t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}