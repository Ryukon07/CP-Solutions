#include <iostream>
#include <vector>

int main(){

    int t;
    std::cin >> t;
    while(t--){
        int n, x;
        std::cin >> n >> x;
        std::vector<int> gasStations(n + 2);
        gasStations[0] = 0;
        gasStations[n + 1] = x;
        for(int i = 1; i <= n; i++){
            std::cin >> gasStations[i];
        }

        int ans = 0;
        for(int i = 1; i < n + 2; i++){
            ans = std::max(ans, gasStations[i] - gasStations[i - 1]);
        }

        std::cout << std::max(ans, 2 * (x - gasStations[n])) << std::endl;
    }

    return 0;
}