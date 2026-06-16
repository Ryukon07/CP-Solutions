#include <iostream>
#include <vector>
#include <string>

void solve(){
    int n; std::cin >> n;
    std::string s; std::cin >> s;

    bool found = false;

    for(int i = 0; i < 26 && !found; i++){
        std::string ans = "";
        ans += char('a' + i);
        if(s.find(ans) == std::string::npos){
            std::cout << ans << "\n";
            found = true;
        }
    }

    for(int i = 0; i < 26 && !found; i++){
        for(int j = 0; j < 26 && !found; j++){
            std::string ans = "";
            ans += char('a' + i);
            ans += char('a' + j);
            if(s.find(ans) == std::string::npos){
                std::cout << ans << "\n";
                found = true;
            }
        }
    }

    for(int i = 0; i < 26 && !found; i++){
        for(int j = 0; j < 26 && !found; j++){
            for(int k = 0; k < 26 && !found; k++){
                std::string ans = "";
                ans += char('a' + i);
                ans += char('a' + j);
                ans += char('a' + k);
                if(s.find(ans) == std::string::npos){
                    std::cout << ans << "\n";
                    found = true;
                }
            }
        }
    }

}

int main(){
    int t; std::cin >> t;
    while(t--){
        solve();
    }
}