#include <iostream>
#include <vector>

void solve(){
    int n; std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        if(a[i] == 1){
            a[i]++;
        }
    }

    for(int i = 1; i < n; i++){
        if(a[i] % a[i - 1] == 0){
            a[i]++;
        }
    }

    for(int i = 0; i < n; i++){
        std::cout << a[i] << " ";
    }
    std::cout << "\n";

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}