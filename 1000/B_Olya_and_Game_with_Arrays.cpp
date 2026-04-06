#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void solve(){
    int n; std::cin >> n;

    long long lowest1 = 1e9;
    std::vector<int> seconds;
    while(n--){
        int x; std::cin >> x;
        std::vector<int> add(x);
        for(int i = 0; i < x; i++) std::cin >> add[i];
        std::sort(add.begin(), add.end());

        seconds.push_back(add[1]);
        lowest1 = std::min(lowest1, (long long)add[0]);
    }

    std::sort(seconds.begin(), seconds.end());
    long long secondmin = seconds[0];
    long long sum = std::accumulate(seconds.begin(), seconds.end(), 0LL);

    long long ans = lowest1 + sum - secondmin;
    std::cout << ans << std::endl;

}

int main(){
    int t; std::cin >> t;
    while(t--){
        solve();
    }
}