#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void solve(){
    int n; std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> freq;

    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        freq[a[i]]++;
    }

    for(auto &pair : freq){
        if(pair.second == 1){
            std::cout << -1 << "\n";
            return;
        }
    }

    std::vector<int> ans(n);
    for(int i = 0; i < n; i++) ans[i] = i + 1;

    int l = 0, r = 0;
    while(r < n){
        if(a[l] == a[r]){
            r++;
        }else{
            std::rotate(ans.begin() + l, ans.begin() + l + 1, ans.begin() + r);
            l = r;
        }
    }

    std::rotate(ans.begin() + l, ans.begin() + l + 1, ans.begin() + r);

    for(int i = 0; i < n; i++) std::cout << ans[i] << " ";
    std::cout << "\n";

}


int main(){
    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}