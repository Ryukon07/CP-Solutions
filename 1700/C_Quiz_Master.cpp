#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
const ll INF = 1e18;

std::vector<ll> divisors[100001];

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; ++i) std::cin >> a[i];

    std::sort(a.begin(), a.end());

    ll l = 0, r = 0, ans = INF;
    std::vector<ll> freq(m + 1, 0);
    ll check = 0;

    while(r < n){
        for(ll d : divisors[a[r]]){
            if(d > m) break;
            freq[d]++;
            if(freq[d] == 1) check++;
        }
        while(check == m){
            ans = std::min(ans, a[r] - a[l]);
            for(ll d : divisors[a[l]]){
                if(d > m) break;
                freq[d]--;
                if(freq[d] == 0) check--;
            }
            l++;
        }
        r++;
    }

    std::cout << (ans == INF ? -1 : ans) << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(ll i = 1; i <= 100000; ++i){
        for(ll j = i; j <= 100000; j += i) divisors[j].push_back(i);
    }

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;

}