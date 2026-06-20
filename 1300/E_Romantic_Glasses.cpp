#include <iostream>
#include <vector>
#include <map>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);

    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::vector<ll> prefOddSum(n+1, 0), prefEvenSum(n+1, 0);
    for(ll i = 0; i < n; i++){
        prefOddSum[i+1] = prefOddSum[i];
        prefEvenSum[i+1] = prefEvenSum[i];
        if(i % 2 == 0){
            prefEvenSum[i+1] += a[i];
        }else{
            prefOddSum[i+1] += a[i];
        }
    }

    std::map<ll, ll> freq;
    for(ll i = 1; i <= n; i++){
        ll diff = prefEvenSum[i] - prefOddSum[i];
        freq[diff]++;
        if(diff == 0 || freq[diff] == 2){
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}