#include <iostream>
#include <vector>
#include <algorithm>

void solve(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    std::vector<int> b, c;


    bool all_equal = true;
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        if(i > 0 && a[i] != a[i-1]){
            all_equal = false;
        }

        if(a[i] % 2 == 0){
            c.push_back(a[i]);
        }else{
            b.push_back(a[i]);
        }
    }
    
    if(all_equal){
        std::cout << -1 << std::endl;
        return;
    }

    if(b.empty()){
        auto it = std::max_element(c.begin(), c.end());
        int x = *it;

        std::copy_if(c.begin(), c.end(), std::back_inserter(b), [x](int val){
            return val == x;
        });

        auto new_end = std::remove_if(c.begin(), c.end(), [x](int val){
            return val == x;
        });
        c.erase(new_end, c.end());

        std::vector<int> temp = b;
        b = c;
        c = temp;
    }else if(c.empty()){
        auto it = std::max_element(b.begin(), b.end());
        int x = *it;

        std::copy_if(b.begin(), b.end(), std::back_inserter(c), [x](int val){
            return val == x;
        });

        auto new_end = std::remove_if(b.begin(), b.end(), [x](int val){
            return val == x;
        });
        b.erase(new_end, b.end());
    }

    std::cout << b.size() << " " << c.size() << std::endl;
    for(int x : b){
        std::cout << x << " ";
    }
    std::cout << std::endl;
    for(int x : c){
        std::cout << x << " ";
    }
    std::cout << std::endl;

}

int main(){

    int t;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}