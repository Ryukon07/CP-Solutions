#include <iostream>

void solve(){
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    int ans = 0;

    while(b < d){
        b++;
        a++;
        ans++;
    }

    while(a > c){
        a--;
        ans++;
    }

    if(a == c && b == d){
        std::cout << ans << std::endl;
    }
    else{
        std::cout << -1 << std::endl;
    }   

}

int main(){

    int t;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}