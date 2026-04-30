#include <iostream>
#include <string>

void solve(){
    std::string a, b; std::cin >> a >> b;
    int lcs = 0;
    int n = a.size(), m = b.size();
    
    for(int l = 1; l <= std::min(n, m); l++){
        for(int i = 0; i + l <= n; i++){
            for(int j = 0; j + l <= m; j++){
                if(a.substr(i, l) == b.substr(j, l)){
                    lcs = std::max(lcs, l);
                }
            }
        }
    }

    std::cout << a.size() + b.size() - 2*lcs << std::endl;
}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}