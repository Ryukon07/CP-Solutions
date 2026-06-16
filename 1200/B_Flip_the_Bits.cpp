#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::string a, b; std::cin >> a >> b;

    std::vector<ll> ones(n + 1, 0);
    for(ll i = 0; i < n; i++){
        ones[i + 1] = ones[i] + (a[i] - '0');
    }

    bool flipped = false;
    bool possible = true;

    for(ll i = n - 1; i >= 0; i--){
        char c = (flipped ? (a[i] == '1' ? '0' : '1') : a[i]);

        if(c == b[i]) continue;

        ll len = i + 1;

        if(len % 2 == 1) {possible = false; break;}

        ll onesCount = (flipped ? (len - ones[len]) : ones[len]);

        if(onesCount != len / 2) {possible = false; break;}

        flipped = !flipped;
    }

    std::cout << (possible ? "YES" : "NO") << "\n";

}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}