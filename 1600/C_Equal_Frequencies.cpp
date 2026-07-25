#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::string s; std::cin >> s;

    std::vector<std::pair<ll, char>> freq(26);

    for(ll i = 0; i < 26; i++) freq[i] = {0, (char)('a' + i)};
    for(char c : s) freq[c - 'a'].first++;

    std::sort(freq.rbegin(), freq.rend());

    ll ans = LLONG_MAX;
    ll best = 1;

    for(ll k = 1; k <= 26; k++){
        if (n % k != 0) continue;
        ll c = n / k;
        ll cost = 0;
        for(ll i = 0; i < k; i++) cost += std::min(freq[i].first, c);
        ll change = n - cost;
        if(change < ans){
            ans = change;
            best = k;
        }
    }

    ll c = n / best;
    std::vector<bool> used(26, false);
    std::vector<ll> need(26, 0);
    for(ll i = 0; i < best; i++){
        char cx = freq[i].second;
        used[cx - 'a'] = true;
        need[cx - 'a'] = c;
    }

    std::string t(n, '?');
    for(ll i = 0; i < n; i++){
        ll idx = s[i] - 'a';
        if(used[idx] && need[idx] > 0){
            t[i] = s[i];
            need[idx]--;
        }
    }

    std::vector<char> extras;
    for(ll i = 0; i < 26; i++){
        while(need[i] > 0){
            extras.push_back((char)('a' + i));
            need[i]--;
        }
    }

    ll extraI = 0;
    for(ll i = 0; i < n; i++){
        if(t[i] == '?'){
            t[i] = extras[extraI++];
        }
    }

    std::cout << ans << "\n" << t << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
}