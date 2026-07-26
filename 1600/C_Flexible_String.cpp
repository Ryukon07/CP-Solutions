#include <iostream>
#include <vector>
#include <string>
#include <set>

using ll = long long;

void solve(){
    ll n, k; std::cin >> n >> k;
    std::string a, b; std::cin >> a >> b;

    std::set<char> unique(a.begin(), a.end());
    std::vector<char> uniqueVec(unique.begin(), unique.end());
    ll m = uniqueVec.size();

    ll max = 0;

    for(ll i = 0; i < (1LL << m); i++){
        if(__builtin_popcount(i) > k) continue;

        std::vector<bool> keep(26, false);
        for(ll j = 0; j < m; j++){
            if(i & (1 << j)){
                keep[uniqueVec[j] - 'a'] = true;
            }
        }

        ll curr = 0, len = 0;
        for(ll j = 0; j < n; j++){
            if(a[j] == b[j] || keep[a[j] - 'a']){
                len++;
            } else {
                curr += len * (len + 1) / 2;
                len = 0;
            }
        }

        curr += len * (len + 1) / 2;
        max = std::max(max, curr);
    }

    std::cout << max << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;
}