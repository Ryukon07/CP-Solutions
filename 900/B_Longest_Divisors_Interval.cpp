#include <iostream>

void solve(){
    long long n; std::cin >> n;

    int ans = 0;
    bool flag = true;
    while(flag){
        ans++;
        if(n % ans != 0){
            flag = false;
        }
    }

    std::cout << ans - 1 << std::endl;
}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}