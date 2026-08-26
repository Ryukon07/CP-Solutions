#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<ll> a(n);

    for(ll i = 0; i < n; i++) std::cin >> a[i];

    ll ans = n * (n + 1) / 2;

    for(ll i = 0; i < n - 1; i++){
        if(a[i] != a[i + 1]){
            ans += ((i + 1) * (n - (i + 1)));
        }
    }

    while(m--){
        ll i , x; std::cin >> i >> x;
        i--;

        if(i > 0 && a[i] != a[i - 1]) ans -= (i * (n - i));
        if(i < n - 1 && a[i] != a[i + 1] ) ans -= ((i + 1) * (n - (i + 1)));

        a[i] = x;

        if(i > 0 && a[i] != a[i - 1]) ans += (i * (n - i));
        if(i < n - 1 && a[i] != a[i + 1]) ans += ((i + 1) * (n - (i + 1)));

        std::cout << ans << "\n";

    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}