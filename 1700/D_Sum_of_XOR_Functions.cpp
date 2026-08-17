#include <iostream>
#include <vector>

using ll = long long;
const ll MOD = 998244353;

void add(ll& a, ll b) {a += b; a %= MOD;}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; ++i) std::cin >> a[i];

    ll ans = 0;
    for(ll bit = 0; bit < 31; bit++){
        ll sum = 0;
        ll countOne = 0, countZero = 0, sumOne = 0, sumZero = 0;
        for(ll i = 0; i < n; i++){
            add(sumOne, countOne); add(sumZero, countZero);
            if(a[i] & (1 << bit)){
                std::swap(countOne, countZero); std::swap(sumOne, sumZero);
                countOne++; sumOne++;
            }else{
                countZero++; sumZero++;
            }
            add(sum, sumOne);
        }
        add(ans, (sum << bit));
    }

    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}