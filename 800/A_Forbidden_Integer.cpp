#include <iostream>
#include <vector>

void solve(){
    int n, k, x;
    std::cin >> n >> k >> x;

    std::vector<int> ans;

    if(x != 1){
        while(n){
            ans.push_back(1);
            n--;
        }
    }else{
        if(n % 2 == 0){
            if(2 <= k){
                while(n){
                    ans.push_back(2);
                    n -= 2;
                }
            }
        }else{
            if(3 <= k){
                ans.push_back(3);
                n -= 3;
                while(n){
                    ans.push_back(2);
                    n -= 2;
                }
            }
        }
    }

    if(!n){
        std::cout << "YES" << std::endl;
        std::cout << ans.size() << std::endl;
        for(int i : ans){
            std::cout << i << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "NO" << std::endl;

    }

}

int main(){

    int t;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}