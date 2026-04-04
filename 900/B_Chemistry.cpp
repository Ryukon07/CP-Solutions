#include <iostream>
#include <vector>

void solve(){
    int n, k;
    std::cin >> n >> k;
    std::string s; std::cin >> s;

    std::vector<int> freq(26, 0);
    for(char c : s){
        freq[c - 'a']++;
    }

    int oddCount = 0;
    for(int count : freq){
        if(count % 2 != 0){
            oddCount++;
        }
    }

    if(oddCount > k + 1){
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
}

int main(){
    int t;
    std::cin >> t;
    while(t--){
        solve();
    }
}