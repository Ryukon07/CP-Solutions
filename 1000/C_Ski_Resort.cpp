#include <iostream>
#include <vector>

void solve(){
    long long n, k, q; std::cin >> n >> k >> q;
    std::vector<long long> a(n);
    for(long long i = 0; i < n; i++) std::cin >> a[i];

    long long countOf1 = 0;
    long long ans = 0;
    for(long long i = 0; i < n; i++){
        if(a[i] <= q) countOf1++;
        else{
            if(countOf1 >= k){
                ans += ((countOf1 - k + 1) * (countOf1 - k + 2)) / 2;
            }
            countOf1 = 0;
        }
    }

    if(countOf1 >= k){
        ans += ((countOf1 - k + 1) * (countOf1 - k + 2)) / 2;
    }

    std::cout << ans << std::endl;

}

int main(){

    long long t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}