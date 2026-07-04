#include <iostream>
#include <vector>

using ll = long long;

bool isValid(const std::string& s, ll n) {
    ll temp = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] == '(') temp++;
        else temp--;
    }
    return temp == 0;
}

void solve(){
    ll n; std::cin >> n;
    std::string s; std::cin >> s;

    if(!isValid(s, n)){
        std::cout << -1 << std::endl;
        return;
    }

    bool isRBS = true, isRevRBS = true;
    ll bal = 0, revBal = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] == '(') bal++;
        else bal--;
        if(bal < 0) isRBS = false;

        if(s[i] == ')') revBal++;
        else revBal--;
        if(revBal < 0) isRevRBS = false;
    }

    if(isRBS || isRevRBS){
        std::cout << 1 << std::endl;
        for(ll i = 0; i < n; i++) std::cout << 1 << " ";
        std::cout << std::endl;
        return;
    }

    ll colorCount = 1;
    std::vector<ll> colors(n, 0);
    std::vector<ll> stack;
    std::vector<ll> left;

    for(ll i = 0; i < n; i++){
        if(s[i] == '('){
            stack.push_back(i);
        } else {
            if(!stack.empty()){
                ll idx = stack.back();
                stack.pop_back();
                colors[idx] = 1;
                colors[i] = 1;
            }else{
                left.push_back(i);
            }
        }
    }

    if(!stack.empty()){

        colorCount = 2;

        for(ll i = 0; i < left.size(); i++){
            ll cIdx = left[i];
            ll openIdx = stack.back();
            stack.pop_back();
            colors[cIdx] = 2;
            colors[openIdx] = 2;
        }
    }

    std::cout << colorCount << std::endl;
    for(ll i = 0; i < n; i++){
        std::cout << colors[i] << " ";
    }
    std::cout << std::endl;

}

int main(){
    ll t; std::cin >> t;
    while(t--) solve();
}