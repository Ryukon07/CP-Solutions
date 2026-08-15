#include <iostream>
#include <vector>
#include <set>
#include <queue>

using ll = long long;

void solve(){
    ll n, k; std::cin >> n >> k;

    std::vector<std::set<ll>> directed(n);
    std::vector<ll> indegree(n, 0);

    for(ll i = 0; i < k; i++){
        std::vector<ll> temp(n);
        for(ll j = 0; j < n; j++){
            std::cin >> temp[j];
            temp[j]--;
        }

        for(ll j = 1; j < n - 1; j++){
            ll u = temp[j];
            ll v = temp[j + 1];
            if(directed[u].find(v) == directed[u].end()){
                directed[u].insert(v);
                indegree[v]++;
            }
        }
    }

    ll check = 0;
    std::queue<ll> q;
    for(ll i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        ll node = q.front(); q.pop(); check++;
        for(auto &x : directed[node]){
            indegree[x]--;
            if(indegree[x] == 0){
                q.push(x);
            }
        }
    }

    if(check == n) std::cout << "YES\n";
    else std::cout << "NO\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

    return 0;

}