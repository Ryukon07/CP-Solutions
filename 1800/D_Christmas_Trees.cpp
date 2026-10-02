#include <iostream>
#include <vector>
#include <queue>
#include <map>

using ll = long long;

void solve(){
    ll n, m; std::cin >> n >> m;
    std::queue<ll> q;
    std::map<ll, ll> dist;
    for(ll i = 0; i < n; i++){
        ll x; std::cin >> x;
        q.push(x);
        dist[x] = 0;
    };

    std::vector<ll> ans;
    ll total = 0;
    
    while(!q.empty() && ans.size() < m){
        ll x = q.front(); q.pop();
        ll left = x - 1, right = x + 1;
        if(dist.find(left) == dist.end()){
            dist[left] = dist[x] + 1;
            total += dist[left];
            ans.push_back(left);
            q.push(left);
            if(ans.size() == m) break;
        }
        if(dist.find(right) == dist.end()){
            dist[right] = dist[x] + 1;
            total += dist[right];
            ans.push_back(right);
            q.push(right);
            if(ans.size() == m) break;
        }

        if(ans.size() >= m) break;
    }

    std::cout << total << "\n";
    for(ll i = 0; i < m; i++) std::cout << ans[i] << " ";
    
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}