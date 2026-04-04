#include <iostream>

void solve(){
    int n; std::cin >> n;

    int count2 = 0, count3 = 0;
    while(n > 0 && n % 3 == 0){
        count3++;
        n /= 3;
    }

    while(n > 0 && n % 2 == 0){
        count2++;
        n /= 2;
    }

    if(n > 1 || count2 > count3) std::cout << "-1\n";
    else std::cout << 2 * (count3 - count2) + count2 << "\n";
}

int main(){
    int t; std::cin >> t;
    while(t--){
        solve();
    }
}