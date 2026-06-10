#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<ll> a(m); for(ll &x : a) std::cin >> x;

    std::vector<ll> gaps;
    std::sort(a.begin(), a.end());

    for(ll i = 0; i < m - 1; i++){
        gaps.push_back(a[i+1] - a[i] - 1);
    }
    gaps.push_back(a[0] + n - a[m-1] - 1);

    std::sort(gaps.rbegin(), gaps.rend());

    ll saved = 0, days = 0;
    for(ll gap : gaps){
        ll cur = gap - 2 * days;
        if(cur > 0){
            saved++;
            cur -= 2;
            if(cur > 0){
                saved += cur;
            }
            days += 2;
        }
    }

    std::cout << n - saved << "\n";

}

int main(){

    ll t;std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}