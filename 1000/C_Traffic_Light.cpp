#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

void solve(){
    long long n; char c; std::cin >> n >> c; n *= 2;
    std::string s; std::cin >> s; s += s;

    long long ans = 0;
    long long lastGreenIndex = -1;

    for(long long i = n - 1; i >= 0; i--){
        if(s[i] == 'g'){
            lastGreenIndex = i;
        }

        if(s[i] == c){
            long long diff = lastGreenIndex - i;
            ans = std::max(ans, diff);
        }
    }

    std::cout << ans << "\n";

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}