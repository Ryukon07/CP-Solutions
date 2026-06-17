#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    int n; std::cin >> n;
    std::vector<ll> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];

    std::vector<bool> visited(n, false);

    visited[0] = true;

    std::vector<std::pair<int, int>> edges;

    bool changed = true;
    while(changed){
        changed = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i] && !visited[j] && a[i] != a[j]){
                    edges.push_back({i + 1, j + 1});
                    visited[j] = true;
                    changed = true;
                }
            }
        }
    }

    bool check = true;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            check = false;
            break;
        }
    }

    if(!check){
        std::cout << "NO\n";
    }else{
        std::cout << "YES\n";
        for(auto [u, v] : edges){
            std::cout << u << " " << v << "\n";
        }
    }

}

int main(){
    int t; std::cin >> t;
    while(t--){
        solve();
    }
}