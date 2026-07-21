#include <iostream>
#include <vector>
#include <queue>

using ll = long long;

void solve(){
    ll n, k1, k2; std::cin >> n >> k1 >> k2;
    std::vector<ll> a(n), b(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];
    for(ll i = 0; i < n; i++) std::cin >> b[i];

    std::priority_queue<ll> pq;
    for(ll i = 0; i < n; i++){
        pq.push(std::abs(a[i] - b[i]));
    }

    ll k = k1 + k2;
    ll ans = 0;
    while(k--){
        ll top = pq.top(); pq.pop();
        if(top == 0){
            pq.push(1);
        }else{
            pq.push(top - 1);
        }
    }

    while(!pq.empty()){
        ll top = pq.top(); pq.pop();
        ans += top * top;
    }
    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}