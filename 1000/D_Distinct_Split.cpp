#include <iostream>
#include <unordered_set>
#include <vector>

void solve(){
    int n; std::cin >> n;
    std::string s; std::cin >> s;

    std::unordered_set<char> distinct_characters;
    
    std::vector<int> prefix(n + 1, 0), suffix(n + 1, 0);
    for(int i = 0; i < n; ++i){
        distinct_characters.insert(s[i]);
        prefix[i + 1] = distinct_characters.size();
    }
    distinct_characters.clear();
    for(int i = n - 1; i >= 0; --i){
        distinct_characters.insert(s[i]);
        suffix[i] = distinct_characters.size();
    }

    int answer = 0;
    for(int i = 1; i < n; ++i){
        answer = std::max(answer, prefix[i] + suffix[i]);
    }
    std::cout << answer << "\n";

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}