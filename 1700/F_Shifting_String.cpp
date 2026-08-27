#include <iostream>
#include <vector>
#include <numeric>

using ll = long long;

ll period(const std::string& str){
    ll n = str.size();
    for(ll i = 1; i <= n; i++){
        if(n % i == 0){
            bool valid = true;
            for(ll j = 0; j < n; j++){
                if(str[j] != str[(j + i) % n]){
                    valid = false;
                    break;
                }
            }
            if(valid) return i;
        }
    }
    return n;
}

void solve(){
    ll n; std::cin >> n;
    std::string s; std::cin >> s;

    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) {std::cin >> a[i]; a[i]--;}

    std::vector<bool> visited(n, false);
    ll ans = 1;
    for(ll i = 0; i < n; i++){
        if(!visited[i]){
            std::string str = "";
            ll curr = i;
            while(!visited[curr]){
                visited[curr] = true;
                str += s[curr];
                curr = a[curr];
            }

            ll perod = period(str);
            ans = std::lcm(ans, perod);
        }
    }

    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t; std::cin >> t;
    while(t--) solve();
    return 0;
}