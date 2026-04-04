#include <iostream>
#include <set>

void solve(){
    int a, b; std::cin >> a >> b;
    int kx, ky; std::cin >> kx >> ky;
    int qx, qy; std::cin >> qx >> qy;

    std::set<std::pair<int, int>> knightPositionForKing = {
        {kx + a, ky + b},
        {kx + a, ky - b},
        {kx - a, ky + b},
        {kx - a, ky - b},
        {kx + b, ky + a},
        {kx + b, ky - a},
        {kx - b, ky + a},
        {kx - b, ky - a}
    };
    std::set<std::pair<int, int>> knightPositionForQueen = {
        {qx + a, qy + b},
        {qx + a, qy - b},
        {qx - a, qy + b},
        {qx - a, qy - b},
        {qx + b, qy + a},
        {qx + b, qy - a},
        {qx - b, qy + a},
        {qx - b, qy - a}
    };

    int ans = 0;

    for(const auto& pos : knightPositionForKing){
        if(knightPositionForQueen.count(pos)){
            ans++;
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