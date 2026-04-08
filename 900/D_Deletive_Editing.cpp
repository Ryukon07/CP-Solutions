#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void solve(){
    std::string s, t; std::cin >> s >> t;
    std::vector<int> ind;

    for(int i = t.size() - 1; i >= 0; i--){
        char c = t[i];
        for(int j = s.size() - 1; j >= 0; j--){
            if(s[j] == c && std::find(ind.begin(), ind.end(), j) == ind.end()){
                ind.push_back(j);
                break;     
            }
        }
    }

    if(ind.size() != t.size()){
        std::cout << "NO" << std::endl;
        return;
    }

    bool strictlyDecreasing = true;
    for(int i = 1; i < ind.size(); i++){
        if(ind[i] >= ind[i - 1]){
            strictlyDecreasing = false;
            break;
        }
    }

    if(strictlyDecreasing){
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

}

int main(){

    int n; std::cin >> n;
    while(n--){
        solve();
    }

    return 0;
}