#include <iostream>
#include <vector>
#include <algorithm>

bool sortCond(const std::pair<int, int>& a, const std::pair<int, int>& b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

void solve(){
    int n, k; std::cin >> n >> k;
    
    std::vector<std::pair<int, int>> monsters(n);
    for(int i = 0; i < n; i++){
        std::cin >> monsters[i].first;
        monsters[i].second = i + 1;
    }

    for(int i = 0; i < n; i++){
        monsters[i].first = monsters[i].first % k;
        if(monsters[i].first == 0) monsters[i].first = k;
    }

    std::sort(monsters.begin(), monsters.end(), sortCond);

    for(int i = 0; i < n; i++){
        std::cout << monsters[i].second << " ";
    }
    std::cout << std::endl;

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}