#include <iostream>

void solve(){
    int n; std::cin >> n;
    std::string s; std::cin >> s;

    int open = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            open++;
        }
        else{
            if(open > 0){
                open--;
            }
            else{
                ans++;
            }
        }
    }
    std::cout << ans << "\n";
}

int main(){
    int t; std::cin >> t;
    while(t--){
        solve();
    }
}