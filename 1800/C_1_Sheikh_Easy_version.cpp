#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n, q; std::cin >> n >> q;
    std::vector<ll> a(n + 1), P(n + 1, 0), X(n + 1, 0);

    for(ll i = 1; i <= n; i++){
        std::cin >> a[i];
        P[i] = P[i - 1] + a[i];
        X[i] = X[i - 1] ^ a[i];
    }

    ll qL, qR; std::cin >> qL >> qR;

    auto get = [&](ll l, ll r){
        return P[r] - P[l - 1] - (X[r] ^ X[l - 1]);
    };

    ll m = get(qL, qR), bestl = 1, bestr = n, minlen = n;

    ll r = 1;
    for(ll l = 1; l <= n; l++){
        r = std::max(r, l);
        while(r <= n && get(l, r) < m) r++;

        if(r <= n && get(l, r) == m){
            if(r - l + 1 < minlen){
                minlen = r - l + 1;
                bestl = l;
                bestr = r;
            }
        }

    }

    std::cout << bestl << " " << bestr << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}