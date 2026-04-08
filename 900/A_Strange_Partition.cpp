#include <iostream>
#include <vector>

static long long ceil(long long a, long long b) {
    return (a + b - 1) / b;
}

void solve(){
    int n;
    long long x;
    std::cin >> n >> x;
    std::vector<long long> a(n);

    long long min = 0, sum = 0;
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        sum += a[i];
        min += ceil(a[i], x);
    }

    std::cout << ceil(sum, x) << " " << min << std::endl;
}

int main(){

    int t; std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}