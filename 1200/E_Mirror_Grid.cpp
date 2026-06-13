#include <iostream>
#include <vector>
#include <string>

void solve(){
    int n; std::cin >> n;
    std::vector<std::vector<int>> grid(n, std::vector<int>(n));
    for(int i = 0; i < n; ++i){
        std::string row; std::cin >> row;
        for(int j = 0; j < n; ++j){
            grid[i][j] = row[j] - '0';
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int zeros = 0, ones = 0;
            if(grid[i][j] == 0) zeros++;
            else ones++;

            if(grid[j][n - 1 - i] == 0) zeros++;
            else ones++;

            if(grid[n - 1 - i][n - 1 - j] == 0) zeros++;
            else ones++;

            if(grid[n - 1 - j][i] == 0) zeros++;
            else ones++;

            if((zeros == 0) || (ones == 0)) continue;

            if(zeros >= ones){
                ans += ones;
                grid[i][j] = 0;
                grid[j][n - 1 - i] = 0;
                grid[n - 1 - i][n - 1 - j] = 0;
                grid[n - 1 - j][i] = 0;
            } else {
                ans += zeros;
                grid[i][j] = 1;
                grid[j][n - 1 - i] = 1;
                grid[n - 1 - i][n - 1 - j] = 1;
                grid[n - 1 - j][i] = 1;
            }
        }
    }
    std::cout << ans << "\n";
}

int main(){
    int t; std::cin >> t;
    while(t--){
        solve();
    }
}