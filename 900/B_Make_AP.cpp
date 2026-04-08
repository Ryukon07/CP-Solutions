#include <iostream>

void solve(){
    int a, b, c; std::cin >> a >> b >> c;
    int A = 2 * b - c, B = (a + c) / 2, C = 2 * b - a;
    bool valid = false;
    if(A / a> 0 && A % a == 0) valid = true;
    else if (B / b > 0 && B % b == 0 && (c-a) % 2 == 0) valid = true;
    else if (C / c > 0 && C % c == 0) valid = true;

    if(valid) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}