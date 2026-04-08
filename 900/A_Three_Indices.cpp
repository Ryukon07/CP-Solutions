#include <iostream>
#include <vector>

void solve(){
    int n; std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];

    for(int j = 1; j < n - 1; j++){
        int i = -1, k = -1;
        for(int l = 0; l < j; l++){
            if(a[l] < a[j]){
                i = l;
                break;
            }
        }
        for(int l = n - 1; l > j; l--){
            if(a[l] < a[j]){
                k = l;
                break;
            }
        }

        if(i != -1 && k != -1){
            std::cout << "YES\n" << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
            return;
        }
    }

    std::cout << "NO\n";

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}