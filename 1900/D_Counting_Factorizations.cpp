#include <iostream>
#include <vector>  

using ll = long long;
ll n; 
std::vector<ll> arr, freq, primes;
std::vector<std::vector<ll>> dp;
const ll MOD = 998244353;

ll modpow(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b % 2 == 1) {
            ans = ans * a % MOD;
        }

        a = a * a % MOD;
        b /= 2;
    }

    return ans;
}

ll recur(ll i, ll rem){
    if(rem == 0) return 1;
    if(i == primes.size()) return 0;
    if((ll)(primes.size() - i) < rem) return 0;
    if(dp[i][rem] != -1) return dp[i][rem];

    ll skip = recur(i + 1, rem);
    ll take = freq[primes[i]] * recur(i + 1, rem - 1) % MOD;
    return dp[i][rem] = (skip + take) % MOD;
}

void solve(){

    std::cin >> n;
    arr.assign(2 * n, 0);
    ll mx = 0;

    for(ll i = 0; i < 2 * n; i++){
        std::cin >> arr[i];
        mx = std::max(mx, arr[i]);
    }

    
    freq.assign(mx + 1, 0);
    for(ll x: arr) freq[x]++;
    
    std::vector<bool> isPrime(mx + 1, true);
    isPrime[0] = false;
    if(mx >= 1) isPrime[1] = false;
    
    for(ll i = 2; i * i <= mx; i++){
        if(isPrime[i]){
            for(ll j = i * i; j <= mx; j += i){
                isPrime[j] = false;
            }
        }
    }
    
    for(ll i = 2; i <= mx; i++) if(isPrime[i] && freq[i] > 0) primes.push_back(i);
    
    std::vector<ll> fact(2 * n + 1, 1);
    for(ll i = 2; i <= 2 * n; i++) fact[i] = fact[i - 1] * i % MOD;
    
    ll numerator = fact[n];
    ll denominator = 1;
    
    for(ll f: freq) if(f > 0) denominator = denominator * fact[f] % MOD;
    
    ll left = numerator * modpow(denominator, MOD - 2) % MOD;
    
    dp.assign(primes.size() + 1, std::vector<ll>(n + 1, -1));

    std::cout << left * recur(0, n) % MOD << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}