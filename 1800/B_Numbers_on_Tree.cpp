#include <iostream>
#include <vector>

using ll = long long;

ll n, root;
std::vector<ll> c;
std::vector<std::vector<ll>> adj;
std::vector<ll> ans;
bool possible = true;

std::vector<ll> dfs(ll node){
    std::vector<ll> res;
    for(ll child : adj[node]){
        std::vector<ll> childRes = dfs(child);
        res.insert(res.end(), childRes.begin(), childRes.end());
    }
    if(c[node] > res.size()){
        possible = false;
        return {};
    }

    res.insert(res.begin() + c[node], node);
    return res;
}

void solve(){
    std::cin >> n;
    c.resize(n + 1);
    adj.resize(n + 1);
    ans.resize(n + 1);

    for(ll i = 1; i <= n; i++){
        ll p; 
        std::cin >> p >> c[i];
        if(p == 0) root = i;
        else adj[p].push_back(i);
    }

    std::vector<ll> sorted = dfs(root);
    if(!possible){
        std::cout << "NO\n";
    }else{
        std::cout << "YES\n";
        for(ll i = 0; i < sorted.size(); i++){
            ans[sorted[i]] = i + 1;
        }
        for(ll i = 1; i <= n; i++){
            std::cout << ans[i] << (i == n ? "" : " ");
        }
        std::cout << "\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();

}