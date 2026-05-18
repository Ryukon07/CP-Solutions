#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;

bool check(const std::vector<ll>& s, ll mid, ll c){
    ll sum = 0; 
    ll n = s.size();
    for(ll i = 0; i < n; i++){
        ll t =  (s[i] + 2*mid);
        if(t > 1e9) return false; 

        ll sq = t * t;
        
        if(sum + sq > c) return false;
        sum += sq;
    }
    return true;
}

void solve(){
    ll n, c; std::cin >> n >> c;
    std::vector<ll> s(n);
    for(ll i = 0; i < n; i++) std::cin >> s[i];

    ll ans = 0, l = 1, r = 1e9;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        if(check(s, mid, c)){
            ans = mid; 
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    std::cout << ans << "\n";
}

int main(){
    int t; std::cin >> t;
    while(t--){
        solve();
    }
}