#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

struct Segment {
    ll l, r, idx;
};

void solve(){
    ll n; std::cin >> n;

    std::vector<Segment> segments(n);
    for(ll i = 0; i < n; i++){
        std::cin >> segments[i].l >> segments[i].r;
        segments[i].idx = i + 1;
    }

    std::sort(segments.begin(), segments.end(), [](const Segment &a, const Segment &b){
        if(a.l == b.l) return a.r > b.r;
        return a.l < b.l;
    });

    ll mx = segments[0].r, idx = segments[0].idx;
    for(ll i = 1; i < n; i++){
        if(segments[i].r > mx){
            mx = segments[i].r;
            idx = segments[i].idx;
        }else{
            std::cout << segments[i].idx << " " << idx << "\n";
            return;
        }
    }

    std::cout << -1 << " " << -1 << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}