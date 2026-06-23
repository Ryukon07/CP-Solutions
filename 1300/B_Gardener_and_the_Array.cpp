#include <iostream>
#include <vector>

using ll = long long;

int freq[200005];

void solve(){
    ll n; std::cin >> n;
    std::vector<std::vector<ll>> bits(n);

    for(ll i = 0; i < n; i++){
        ll x; std::cin >> x;
        bits[i].resize(x);
        for(ll j = 0; j < x; j++){
            std::cin >> bits[i][j];
            freq[bits[i][j]]++;
        }
    }

    bool totalOK = false;
    for(ll i = 0; i < n; i++){
        bool ok = true;
        for(ll b: bits[i]){
            if(freq[b] < 2){
                ok = false;
                break;
            }
        }
        if(ok) {totalOK = true; break;}
    }

    if(totalOK) std::cout << "Yes\n";
    else std::cout << "No\n";
    

    for(int i = 0; i < n; i++){
        for(ll b: bits[i]){
            freq[b] = 0;
        }
    }

}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

    return 0;
}