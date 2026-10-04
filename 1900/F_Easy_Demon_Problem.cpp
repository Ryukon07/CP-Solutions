#include <iostream>
#include <vector>
#include <map>

using ll = long long;

const ll OFFSET = 400000;
bool ar[800005], br[800005];

auto exists(ll val, const bool arr[]){
    return std::abs(val) <= 400000 && arr[val + OFFSET];
}

void solve(){
    ll n, m, q; std::cin >> n >> m >> q;
    std::vector<ll> a(n), b(m);
    ll sumA = 0, sumB = 0;
    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        sumA += a[i];
    }
    for(ll i = 0; i < m; i++){
        std::cin >> b[i];
        sumB += b[i];
    }

    for(ll i = 0; i < n; i++){
        ll val = sumA - a[i];
        if(std::abs(val) <= 400000){
            ar[val + OFFSET] = true;
        }
    }
    for(ll i = 0; i < m; i++){
        ll val = sumB - b[i];
        if(std::abs(val) <= 400000){
            br[val + OFFSET] = true;
        }
    }

    while(q--){
        ll x; std::cin >> x;
        if(x == 0){
            if(exists(0, ar) || exists(0, br)) std::cout << "YES\n";
            else std::cout << "NO\n";
            continue;
        }
        bool found = false;
        ll absX = std::abs(x);
        for(ll i = 1; i*i <= absX; i++){
            if(x % i == 0){
                ll div = x / i;
                if((exists(i, ar) && exists(div, br)) || (exists(div, ar) && exists(i, br)) || (exists(-i, ar) && exists(-div, br)) || (exists(-div, ar) && exists(-i, br))){found = true; break;}
            }
        }

        if(found) std::cout << "YES\n";
        else std::cout << "NO\n";

    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}