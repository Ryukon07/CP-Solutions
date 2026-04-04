#include <iostream>
int main(){
    int t;
    std::cin >> t;
    while(t--){
        int a, b, c;
        std::cin >> a >> b >> c;
        if(c % 2 == 0){
            std::cout << (a > b ? "First" : "Second") << "\n";
        } else {
            std::cout << (b > a ? "Second" : "First") << "\n";
        }
    }
    return 0;
}