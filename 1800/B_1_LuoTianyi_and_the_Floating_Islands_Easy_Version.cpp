#include <iostream>
#include <vector>

using ll = long long;
const ll MOD = 1e9 + 7;
const ll MAX = 200005;

ll power(ll base, ll exp){
    ll result = 1;
    while(exp > 0){
        if(exp % 2 == 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

void preCompute(std::vector<ll>& fact, std::vector<ll>& invFact){
    fact[0] = 1;
    for(ll i = 1; i < MAX; ++i){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
    for(ll i = MAX - 2; i >= 0; --i){
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(ll n, ll r, const std::vector<ll>& fact, const std::vector<ll>& invFact){
    if(r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

std::vector<std::vector<ll>> adj;
std::vector<ll> size;

void dfs(ll u, ll p){
    size[u] = 1;
    for(ll v : adj[u]){
        if(v == p) continue;
        dfs(v, u);
        size[u] += size[v];
    }
}

void solve(){
    ll n, k; std::cin >> n >> k;

    adj.assign(n + 1, std::vector<ll>());
    size.assign(n + 1, 0);

    std::vector<ll> fact(MAX), invFact(MAX);
    preCompute(fact, invFact);

    for(ll i = 0; i < n - 1; ++i){
        ll u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(k % 2){
        std::cout << 1 << "\n";
        return;
    }

    dfs(1, -1);

    ll sum = 0;
    for(ll i = 2; i <= n; i++){
        ll s = size[i];
        ll ways = (nCr(s, k / 2, fact, invFact) * nCr(n - s, k / 2, fact, invFact)) % MOD;
        sum = (sum + ways) % MOD;
    }

    ll total = nCr(n, k, fact, invFact);
    ll invTotal = power(total, MOD - 2);

    ll ans = (1 + (sum * invTotal) % MOD) % MOD;
    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}