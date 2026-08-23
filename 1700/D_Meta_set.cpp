#include <iostream>
#include <vector>
#include <map>

using ll = long long;

void solve(){
    ll n, m; std::cin >> n >> m;

    std::map<std::vector<ll>, ll> a;
    std::vector<std::vector<ll>> unq(n, std::vector<ll>(m));
    
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            std::cin >> unq[i][j];
        }
        a[unq[i]] = i;
    }

    std::vector<ll> ans(n, 0);

    for(ll i = 0; i < n; i++){
        for(ll j = i + 1; j < n; j++){
            std::vector<ll> tmp;
            for(ll k = 0; k < m; k++){
                if(unq[i][k] != unq[j][k]) tmp.push_back(3 - unq[i][k] - unq[j][k]);
                else tmp.push_back(unq[i][k]);
            }

            auto it = a.find(tmp);
            if(it != a.end()){
                ans[i]++;
                ans[j]++;
                ans[it->second]++;
            }

        }
    }

    ll anss = 0;
    for(ll i = 0; i < n; i++){
        ans[i] /= 3;
        anss += (ans[i] * (ans[i] - 1)) / 2;
    }

    std::cout << anss << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}