#include <iostream>
#include <vector>

int main(){

    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::string s;
        std::cin >> n >> s;
        
        bool isBlocked = false;
        std::vector<int> blocked;
        blocked.push_back(-1);
        for(int i = 0; i < n; i++){
            if(s[i] == '#'){
                blocked.push_back(i);
                isBlocked = true;
            }
        }
        blocked.push_back(n);

        int ans = 0;
        if(isBlocked){
            for(int i = 1; i < blocked.size(); i++){
                int temp = blocked[i] - blocked[i - 1] - 1;
                if(temp == 1){ans += 1;}
                else if(temp == 2){ans += 2;}
                else if(temp > 2){ans = 2; break;}
            }
        }else{
            if(n == 1){ans = 1;}
            else if(n == 2){ans = 2;}
            else{ans = 2;}
        }

        std::cout << ans << std::endl;

    }

    return 0;
}