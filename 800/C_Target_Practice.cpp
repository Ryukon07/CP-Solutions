#include <iostream>
#include <string>
#include <vector>

void solve(){

    std::vector<std::pair<int, int>> targets;

    for(int i = 1; i <= 10; i++){
        std::string s; std::cin >> s;
        for(int j = 1; j <= 10; j++){
            if(s[j-1] == 'X'){
                targets.push_back({i, j});
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < targets.size(); i++){
        if(targets[i].first == 1 || targets[i].first == 10 || targets[i].second == 1 || targets[i].second == 10){
            ans += 1;
        }else if(targets[i].first == 2 || targets[i].first == 9 || targets[i].second == 2 || targets[i].second == 9){
            ans += 2;
        }else if(targets[i].first == 3 || targets[i].first == 8 || targets[i].second == 3 || targets[i].second == 8){
            ans += 3;
        }else if(targets[i].first == 4 || targets[i].first == 7 || targets[i].second == 4 || targets[i].second == 7){
            ans += 4;   
        }else if(targets[i].first == 5 || targets[i].first == 6 || targets[i].second == 5 || targets[i].second == 6){
            ans += 5;
        }
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