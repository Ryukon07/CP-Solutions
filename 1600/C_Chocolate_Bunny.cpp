#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;

    std::vector<ll> ans(n + 1, 0);
    ll max = 1;

    for(ll i = 2; i <= n; i++){
        std::cout << "? " << max << " " << i << std::endl;
        ll x; std::cin >> x;
        
        std::cout << "? " << i << " " << max << std::endl;
        ll y; std::cin >> y;

        if(x > y){
            ans[max] = x;
            max = i;
        }else{
            ans[i] = y;
        }
    }

    ans[max] = n;

    std::cout << "! ";
    for(ll i = 1; i <= n; i++) std::cout << ans[i] << " ";

    std::cout << std::endl;

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}