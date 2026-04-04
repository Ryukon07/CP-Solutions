#include <iostream>
#include <vector>

void solve(){
    int n, q; std::cin >> n >> q;
    std::vector<long long> a(n), prefixSum(n + 1, 0);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        prefixSum[i + 1] = a[i] + prefixSum[i];
    }

    while(q--){
        long long l, r, k; std::cin >> l >> r >> k;
        long long check = prefixSum[n] - (prefixSum[r] - prefixSum[l - 1]) + (r - l + 1) * k;

        if(check % 2 == 1){
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}