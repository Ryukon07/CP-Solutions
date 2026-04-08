#include <iostream>

void solve(){
    int n; std::cin >> n;
    std::string s; std::cin >> s;

    int max = 0;
    for(int i = 0; i < n; i++){
        int temp = 1;
        for(int j = i + 1; j < n; j++){
            if(s[i] == s[j]){
                temp++;
            }else{
                break;
            }
        }
        max = std::max(max, temp);
    }

    std::cout << max + 1 << std::endl;

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}