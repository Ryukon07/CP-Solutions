#include <iostream>
#include <vector>
#include <queue>

using ll = long long;

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];

    std::queue<ll> q;
    for(ll i = 0; i < n; i++){
        q.push(a[i]);

        while(!q.empty() && q.front() < q.size()){
            q.pop();
        }

        std::cout << q.size() << " ";
    }
    std::cout << "\n";

}

int main(){

    ll t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}