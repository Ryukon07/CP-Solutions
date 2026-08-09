#include <iostream>
#include <vector>
#include <queue> 

using ll = long long;

ll dr[4] = {-1, 1, 0, 0};
ll dc[4] = {0, 0, -1, 1};

struct Node{
    ll r, c;
    ll dir;
    ll track;
    ll cnt;
};

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<std::vector<char>> grid(n, std::vector<char>(m));
    ll startR, startC, endR, endC;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            std::cin >> grid[i][j];
            if(grid[i][j] == 'S'){
                startR = i;
                startC = j;
            }
            else if(grid[i][j] == 'T'){
                endR = i;
                endC = j;
            }
        }
    }

    if(startR == endR && startC == endC){
        std::cout << 0 << "\n";
        return;
    }

    std::vector<std::vector<std::vector<std::vector<bool>>>> visited(n, std::vector<std::vector<std::vector<bool>>>(m, std::vector<std::vector<bool>>(4, std::vector<bool>(4, false))));

    std::queue<Node> q;
    for(ll d = 0; d < 4; d++){
        ll newR = startR + dr[d];
        ll newC = startC + dc[d];
        if(newR >= 0 && newR < n && newC >= 0 && newC < m && grid[newR][newC] != '#'){
            visited[newR][newC][d][1] = true;
            q.push({newR, newC, d, 1, 1});
        }
    }

    while(!q.empty()){
        Node curr = q.front(); q.pop();
        if(curr.r == endR && curr.c == endC){
            std::cout << curr.cnt << "\n";
            return;
        }
        for(ll d = 0; d < 4; d++){
            ll newR = curr.r + dr[d];
            ll newC = curr.c + dc[d];
            if(newR < 0 || newR >= n || newC < 0 || newC >= m || grid[newR][newC] == '#') continue;

            ll next = (d == curr.dir) ? (curr.track + 1) : 1;
            if(next > 3) continue;

            if(!visited[newR][newC][d][next]){
                visited[newR][newC][d][next] = true;
                q.push({newR, newC, d, next, curr.cnt + 1});
            }

        }
    }

    std::cout << -1 << "\n";

}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}