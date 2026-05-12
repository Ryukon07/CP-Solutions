#include <iostream>
#include <vector>
#include <algorithm>

void solve(){
    int n; std::cin >> n; 
    std::vector<int> v(n);
    for(int i = 0; i < n; i++) std::cin >> v[i];

    std::sort(v.rbegin(), v.rend());
    for(int i = 0; i < n; i++) std::cout << v[i] << " ";
    std::cout << "\n";
}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}