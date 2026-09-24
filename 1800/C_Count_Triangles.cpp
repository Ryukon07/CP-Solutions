#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll A, B, C, D; std::cin >> A >> B >> C >> D;
    ll S = B + C;

    std::vector<ll> diff(S + 2, 0);
    for(ll i = A; i <= B; i++){
        diff[i + B] += 1;
        diff[i + C + 1] -= 1;
    }

    ll curr = 0, total = 0;
    for(ll i = A + B; i <= S; i++){
        curr += diff[i];
        ll z = std::min(D, i - 1) - C + 1;
        if(z > 0) total += curr * z;
    }

    std::cout << total << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}