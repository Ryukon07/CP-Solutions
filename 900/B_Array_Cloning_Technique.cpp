#include <iostream>
#include <vector>
#include <map>

void solve(){
    int n; std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> freq;

    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        freq[a[i]]++;
    }

    int maxFreq = 0;
    for(const auto& p : freq){
        if(p.second > maxFreq){
            maxFreq = p.second;
        }
    }

    int remaining = n - maxFreq;
    int temp = remaining;
    int ans = 0;
    while(temp > 0){
        ans++;
        temp -= maxFreq;
        maxFreq *= 2;
    }

    std::cout << ans + remaining << std::endl;

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}