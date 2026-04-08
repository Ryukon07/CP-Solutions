#include <iostream>
#include <vector>

void solve(){
    int n; std::cin >> n;
    std::vector<long long> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    long long ans = 0;

    for(int i = n - 2; i >= 0; i--){
        while(a[i] >= a[i + 1] && a[i] > 0){
            a[i] /= 2;
            ans++;
        }

        if(a[i] >= a[i + 1]){
            std::cout << -1 << std::endl;
            return;
        }
    }

    std::cout << ans << std::endl;
}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}