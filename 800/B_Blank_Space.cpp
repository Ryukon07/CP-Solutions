#include <iostream>
#include <vector>

void solve(){
    int n;
    std::cin >> n;
    int longest0 = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        if(x == 0){
            longest0++;
        }else{
            longest0 = 0;
        }
        ans = std::max(ans, longest0);
    }
    std::cout << ans << std::endl;
}

int main(){

    int t;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}