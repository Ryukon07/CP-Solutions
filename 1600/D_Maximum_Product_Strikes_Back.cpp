#include <iostream>
#include <vector>

using ll = long long; 

void check(ll l, ll r, std::vector<ll> &a, ll &two, ll &x, ll &y, ll n){
    if(l > r) return;
    ll twos = 0;
    for(ll i = l; i <= r; i++){
        if(std::abs(a[i]) == 2) twos++;
    }
    if(twos > two){
        two = twos;
        x = l;
        y = n - r - 1;
    }
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);

    for(ll i = 0; i < n; i++) std::cin >> a[i];

    ll two = -1, x = n, y = 0;
    ll l = 0;
    while(l < n){
        while(l < n && a[l] == 0) l++;
        if(l == n) break;

        ll r = l;
        while(r < n && a[r] != 0) r++;

        ll neg = 0, total = 0, firstNeg = -1, lastNeg = -1;

        for(ll i = l; i < r; i++){
            if(a[i] < 0){
                neg++;
                if(firstNeg == -1) firstNeg = i;
                lastNeg = i;
            }
        }

        if(neg % 2 == 0){
            check(l, r - 1, a, two, x, y, n);
        } else {
            check(firstNeg + 1, r - 1, a, two, x, y, n);
            check(l, lastNeg - 1, a, two, x, y, n);
        }

        l = r;
    }

    std::cout << x << " " << y << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}