#include <iostream>
#include <vector>
#include <map>

using ll = long long;

void solve(){
    ll n, q; std::cin >> n >> q;
    std::vector<ll> a(n), t(q);

    std::vector<ll> arr(51, 1e9);

    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        if(arr[a[i]] == 1e9) arr[a[i]] = i;
    }
    
    for(ll i = 0; i < q; i++){
        std::cin >> t[i];
        std::cout << arr[t[i]] + 1 << " ";
        for(ll j = 1; j <= 50; j++){
            if(arr[j] < arr[t[i]]) arr[j]++;
        }
        arr[t[i]] = 0;
    }
}

int main(){
    solve();
}