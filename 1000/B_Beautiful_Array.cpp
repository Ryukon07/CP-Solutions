#include <iostream>
#include <vector>
#include <algorithm>

void solve(){
    long long n, k, b, s; std::cin >> n >> k >> b >> s;

    std::vector<long long> a(n, 0);
    long long min = b * k, max = b * k + (k - 1) * n;

    if(s < min || s > max){
        std::cout << -1 << std::endl;
        return;
    }

    a[0] = b * k;
    s -= a[0];

    for(long long i = 0; i < n; i++){
        long long add = std::min(k - 1, s);
        a[i] += add;
        s -= add;
    }

    for(long long x: a){
        std::cout << x << " ";
    }
    std::cout << std::endl;

}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}