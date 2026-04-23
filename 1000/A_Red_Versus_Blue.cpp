#include <iostream>
#include <string>

void solve(){
    int n, r, b; std::cin >> n >> r >> b;
    std::string ans;

    int rs = r / (b + 1);
    int extra = r % (b + 1);

    for(int i = 0; i < b + 1; i++){
        for(int j = 0; j < rs; j++){
            ans += 'R';
        }
        if(extra > 0){
            ans += 'R';
            extra--;
        }
        if(i < b){
            ans += 'B';
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