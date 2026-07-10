#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n; std::cin >> n;

    ll pos = 0, neg = 0;
    ll totalPos = 0, totalNeg = 0;

    for(ll i = 0; i < n; i++){
        ll x; std::cin >> x;

        if(x > 0) pos++;
        else{
            ll np = neg, nn = pos+1;
            pos = np;
            neg = nn;
        }

        totalPos += pos;
        totalNeg += neg;

    }

    std::cout << totalNeg << " " << totalPos << "\n";

}

int main(){
    solve();
}