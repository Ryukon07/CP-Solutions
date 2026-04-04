#include <iostream>
#include <string>

void solve(){
    int n;
    std::string s;
    std::cin >> n >> s;
    int ans = 0;

    int i = 0; int j = n - 1;
    while(i < j){
        if(s[i] != s[j]){
            ans++;
            i++; j--;
        }else{
            break;
        }
    }

    std::cout << n - (ans * 2) << std::endl;

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}