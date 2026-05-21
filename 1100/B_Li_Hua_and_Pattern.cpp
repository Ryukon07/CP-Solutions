#include <iostream>
#include <vector>

using ll = long long;

ll opsCal(std::vector<std::vector<ll>>& mat, ll n){
    ll ops = 0;
    for(ll i = 0; i < n/2; i++){
        for(ll j = 0; j < n; j++){
            if(mat[i][j] != mat[n-1-i][n-1-j]) ops++;
        }
    }
    if(n % 2 == 1){
        for(ll j = 0; j < n/2; j++){
            if(mat[n/2][j] != mat[n/2][n-1-j]) ops++;
        }
    }
    return ops;
}

void solve(){
    ll n, k; std::cin >> n >> k;
    std::vector<std::vector<ll>> mat(n, std::vector<ll>(n));   
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            std::cin >> mat[i][j];
        }
    }

    ll ops = opsCal(mat, n);

    if(ops > k){
        std::cout << "NO\n";
    }else{
        if((k - ops) % 2 == 0 || n % 2 == 1){
            std::cout << "YES\n";
        }else{
            std::cout << "NO\n";
        }
    }
}

int main(){

    ll t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}