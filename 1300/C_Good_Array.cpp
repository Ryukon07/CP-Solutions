#include <iostream>
#include <vector>
#include <map>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    ll total = 0;
    std::map<ll, ll> freq;

    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        total += a[i];
        freq[a[i]]++;
    }

    std::vector<ll> ans_indices;
    ll ans = 0;
    
    for(ll i = 0; i < n; i++){
        ll rem = total - a[i];
        if(rem % 2 != 0) continue;
        ll target = rem / 2;

        auto it = freq.find(target);
        if(it == freq.end()) continue;

        ll cnt = it->second;
        if(target == a[i]) cnt--;
        if(cnt > 0){
            ans++;
            ans_indices.push_back(i);
        }
    }

    std::cout << ans << "\n";
    for(ll i = 0; i < ans_indices.size(); i++){
        std::cout << ans_indices[i] + 1 << " ";
    }
    std::cout << "\n";
}

int main(){
    solve();
}