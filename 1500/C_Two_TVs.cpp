#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<std::pair<ll, ll>> a(n);

    for(ll i = 0; i < n; i++) std::cin >> a[i].first >> a[i].second;

    std::sort(a.begin(), a.end());

    ll tv1 = -1, tv2 = -1;

    for(ll i = 0; i < n; i++){
        if(a[i].first > tv1){
            tv1 = a[i].second;
        }else if(a[i].first > tv2){
            tv2 = a[i].second;
        }else{
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}