#include <iostream>
#include <vector>
#include <algorithm>

bool sortCond(const std::pair<int, int>& a, const std::pair<int, int>& b){
    if(a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

void solve(){
    long long n, p; std::cin >> n >> p;
    std::vector<long long> a(n), b(n);
    std::vector<std::pair<long long, long long>> pairs(n);

    for(long long i = 0; i < n; i++) std::cin >> a[i];
    for(long long i = 0; i < n; i++) std::cin >> b[i];
    for(long long i = 0; i < n; i++) pairs[i] = {b[i], a[i]};

    std::sort(pairs.begin(), pairs.end(), sortCond);

    long long ans = p;
    long long total = 1;

    for(long long i = 0; i < n; i++){
        long long cost = pairs[i].first;
        long long value = pairs[i].second;

        if(cost >= p) break;

        if(total + value <= n){
            total += value;
            ans += cost * value;
        }else{
            long long rem = n - total;
            ans += cost * rem;
            break;
        }
    }

    ans += (n - total) * p;

    std::cout << ans << std::endl;

}

int main(){

    long long t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}