#include <iostream>
#include <vector>
#include <algorithm>

void solve(){
    int n; std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];

    std::sort(a.begin(), a.end());

    if(a[0] == a[n-1]){
        std::cout << "NO\n";
        return;
    }else{
        std::cout << "YES\n";
        std::cout << a[n-1] <<  " ";
        for(int i = 0; i < n-1; i++) std::cout << a[i] << " ";
        std::cout << "\n";
    }

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}