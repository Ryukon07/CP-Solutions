#include <iostream>
#include <vector>

using ll = long long;

ll n, best;
std::vector<std::string> genre, artist;
std::vector<std::vector<bool>> dp, adj;

void recur(ll last, ll mask){

    if(dp[last][mask]) return;
    dp[last][mask] = true;

    ll cnt = __builtin_popcount(mask);
    best = std::max(best, cnt);

    for(ll i = 0; i < n; i++){
        if(mask & (1 << i)) continue;
        if(adj[last][i]) recur(i, mask | (1 << i));
    }
}

void solve(){
    std::cin >> n;
    genre.resize(n); artist.resize(n);
    dp.assign(n, std::vector<bool>(1 << n, false));
    adj.assign(n, std::vector<bool>(n, false));
    for(ll i = 0; i < n; ++i) std::cin >> genre[i] >> artist[i];
    for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) adj[i][j] = (genre[i] == genre[j] || artist[i] == artist[j]);

    best = 0;

    for(ll i = 0; i < n; i++) recur(i, 1 << i);

    std::cout << n - best << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
}