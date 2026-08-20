#include <iostream>
#include <vector>

using ll = long long;

const ll MAX = 1e6 + 1;
ll freq[MAX];

void solve(){
    ll n; std::cin >> n; 
    std::vector<ll> a(n), unique;
    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        if(freq[a[i]] == 0) unique.push_back(a[i]);
        freq[a[i]]++;
    }

    ll ans = 0;
    for(ll x: unique){
        ll f = freq[x];

        if(f >= 3) ans += (f * (f - 1) * (f - 2));

        for(ll b = 2; x * b * b <= 1e6; b++){
            ll y = x * b;
            ll z = x * b * b;
            if(freq[y] > 0 && freq[z] > 0) ans += (f * freq[y] * freq[z]);
        }
    }
    
    for(ll x: unique) freq[x] = 0;
    std::cout << ans << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}