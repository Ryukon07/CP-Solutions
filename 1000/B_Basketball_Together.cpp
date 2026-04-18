#include <iostream>
#include <vector>
#include <algorithm>

void solve(){
    int N, D; std::cin >> N >> D;
    std::vector<int> P(N);
    for(int i = 0; i < N; ++i) std::cin >> P[i];

    std::sort(P.begin(), P.end(), std::greater<int>());

    int ans = 0, track = 0;

    for(int i = 0; i < N; i++){
        int multiplier = (D / P[i]) + 1;
        if(track + multiplier > N) break;
        track += multiplier;
        ans++;
    }
    std::cout << ans << std::endl;

}

int main(){
    solve();
    return 0;
}