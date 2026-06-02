#include <iostream>
#include <vector>
#include <set>

using ll = long long;

bool check(ll x, std::set<ll>& s){
    if(*s.begin() == x) return true;
    else if(*s.rbegin() == x) return true;
    else return false;
}

void solve(){
    ll n; std::cin >> n;
    std::vector<ll> a(n);
    std::set<ll> s;
    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        s.insert(a[i]);
    }

    ll i = 0, j = n-1;
    while(i < j){
        if(check(a[i], s)){
            s.erase(a[i]);
            i++;
        }
        else if(check(a[j], s)){
            s.erase(a[j]);
            j--;
        }
        else break;
    }

    if(i < j) std::cout << i + 1 << " " << j + 1 << std::endl;
    else std::cout << -1 << std::endl;

}

int main(){
    ll t; std::cin >> t;
    while(t--){
        solve();
    }
}