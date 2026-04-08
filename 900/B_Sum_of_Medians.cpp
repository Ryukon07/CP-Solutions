#include <iostream>
#include <vector>

void solve(){
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n*k);
    for(int i = 0; i < n*k; i++) std::cin >> a[i];

    int ans = 0, pointer = n * k;
    while(k--){
        pointer -= (n / 2 + 1);
        ans += a[pointer];
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