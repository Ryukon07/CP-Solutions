#include <iostream>

void solve(){
    std::string s; std::cin >> s;
    int n = s.size();

    int count1 = 0, count0 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') count1++;
        else count0++;
    }

    int lengtht = 0;

    if(count1 == count0){
        std::cout << 0 << std::endl;
    }else{
        for(int i = 0; i < n; i++){
            if(s[i] == '1' && count0 > 0){
                count0--;
                lengtht++;
            }else if(s[i] == '0' && count1 > 0){
                count1--;
                lengtht++;
            }else{
                break;
            }
        }

        std::cout << n - lengtht << std::endl;
    }

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}