#include <iostream>
#include <cmath>

void solve(){
    long long n; std::cin >> n;
    long long root = std::sqrt(n);

    long long ansA = 1, ansB = n - 1;

    for(int i = 2; i <= root; i++){
        if(n % i == 0){
            ansA = n / i;
            ansB = n - ansA;
            break;
        }
    }

    std::cout << ansA << " " << ansB << std::endl;
}

int main(){

    int t;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}