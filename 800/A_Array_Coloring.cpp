#include <iostream>
int main(){
    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        int sum = 0;
        for(int i = 0; i < n; i++){
            int x; std::cin >> x;
            sum += x;
        }
        std::cout << (sum % 2 == 0 ? "YES" : "NO") << "\n";
    }
    return 0;
}