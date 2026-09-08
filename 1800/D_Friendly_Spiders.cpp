#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using ll = long long;

const ll MAX = 300005;
std::vector<ll> primes(MAX + 1, 1);

void sieve(){
    for(ll i = 1; i <= MAX; i++) primes[i] = i;

    for(ll i = 2; i * i <= MAX; i++){
        if(primes[i] == i){
            for(ll j = i * i; j <= MAX; j += i){
                if(primes[j] == j) primes[j] = i;
            }
        }
    }
}

std::vector<ll> get_factors(ll x){
    std::vector<ll> factors;
    while(x > 1){
        ll p = primes[x];
        factors.push_back(p);
        while(x % p == 0) x /= p;
    }
    return factors;
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++) std::cin >> a[i];
    ll s, t; std::cin >> s >> t;

    if(s == t){
        std::cout << 1 << "\n" << s << "\n";
        return;
    }

    std::vector<std::vector<ll>> adj(MAX + n + 1);
    for(ll i = 0; i < n; i++){
        std::vector<ll> factors = get_factors(a[i]);
        for(ll p : factors){

            ll idx = MAX + (i + 1);

            adj[p].push_back(idx);
            adj[idx].push_back(p);
        }
    }

    ll start = MAX + s, end = MAX + t;

    std::vector<ll> parent(MAX + n + 1, -1);
    std::vector<bool> visited(MAX + n + 1, false);
    std::queue<ll> q;

    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        ll u = q.front(); q.pop();
        if(u == end) break;

        for(ll v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if(!visited[end]){
        std::cout << -1 << "\n";
        return;
    }

    std::vector<ll> ans;
    ll curr = end;
    while(curr != -1){
        if(curr > MAX) ans.push_back(curr - MAX);
        curr = parent[curr];
    }

    std::reverse(ans.begin(), ans.end());

    std::cout << ans.size() << "\n";
    for(ll i = 0; i < ans.size(); i++) std::cout << ans[i] << (i + 1 == ans.size() ? "" : " ");
    std::cout << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();

    solve();
    return 0;

}