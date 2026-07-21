#include <iostream>
#include <vector>

using ll = long long;
const ll MOD = 1e9 + 7;

void solve(){
    std::string s; std::cin >> s;
    ll n = s.size();

    std::vector<ll> as; as.push_back(0);

    ll tmp = 0;
    for(ll i = 0; i < n; ++i){
        if(s[i] == 'a') as[tmp]++;
        else if(s[i] == 'b'){
            if(as.back() == 0) continue;
            else{
                as.push_back(0);
                tmp++;
            }
        }
    }

    ll ans = 1;
    for(ll i = 0; i < as.size(); ++i){
        ans *= (as[i] + 1);
        ans %= MOD;
    }
    ans = (ans - 1 + MOD) % MOD;

    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}