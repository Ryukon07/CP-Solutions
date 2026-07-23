#include <iostream>
#include <vector>
#include <climits>

using ll = long long;

bool check(const std::vector<ll>& a, ll mid, ll k){
    ll n = a.size();
    
    for(ll i = 0; i < n; i++){
        if(a[i] >= mid) return true;

        if(i == n - 1) continue;

        ll need = mid - a[i];
        bool valid = false;

        for(ll j = i + 1; j < n && need > 0; j++){
            ll cnt = j - i;
            ll target = mid - cnt;


            if(a[j] >= target) {valid = true; break;}
            need += (target - a[j]);

            if(need > k) break;
        }
        
        if(valid && need <= k) return true;

    }
    return false;
    
}

void solve(){
    ll n, k; std::cin >> n >> k;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    ll low = 1, high = 1e9, ans = 0;
    while(low <= high){
        ll mid = low + (high - low) / 2;

        if(check(a, mid, k)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
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