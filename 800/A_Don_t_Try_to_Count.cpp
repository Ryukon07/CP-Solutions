#include <iostream>
#include <string>

bool check(std::string x, std::string s){
    if(x.size() < s.size()){return false;}

    for(size_t i = 0; i + s.size() <= x.size(); i++){
        if(x.substr(i, s.size()) == s){
            return true;
        }
    }

    return false;
}

void solve(){
    int n, m; 
    std::cin >> n >> m;
    std::string x, s;
    std::cin >> x >> s;

    std::string x0 = x;
    std::string x1 = x0 + x0;
    std::string x2 = x1 + x1;
    std::string x3 = x2 + x2;
    std::string x4 = x3 + x3;
    std::string x5 = x4 + x4;

    int ans = 0;
    if(check(x0, s)){ans = 0;}
    else if(check(x1, s)){ans = 1;}
    else if(check(x2, s)){ans = 2;}
    else if(check(x3, s)){ans = 3;}
    else if(check(x4, s)){ans = 4;}
    else if(check(x5, s)){ans = 5;}
    else{ans = -1;}

    std::cout << ans << std::endl;

}

int main(){

    int t;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}