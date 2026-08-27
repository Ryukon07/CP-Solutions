#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void kadane(ll key, std::vector<ll>& indices, ll& maxSum, ll& l, ll& r, ll& a){
        ll currentSum = 0;
        ll currentL = -1;
        
        for(size_t i = 0; i < indices.size(); i++){
            if(i == 0){
                currentSum = 1;
                currentL = indices[0];
            }else{
                ll gap = indices[i] - indices[i-1] - 1;
                if(currentSum - gap <= 0){
                    currentSum = 1;
                    currentL = indices[i];
                }else{
                    currentSum = currentSum - gap + 1;
                }
            }
            
            if(currentSum > maxSum){
                a = key;
                maxSum = currentSum;
                l = currentL;
                r = indices[i];
        }
        }
    }


void solve(){
    ll n; std::cin >> n;
    std::vector<std::pair<ll, ll>> idx(n);

    for(ll i = 0; i < n; i++){
        std::cin >> idx[i].first;
        idx[i].second = i + 1;
    }

    std::sort(idx.begin(), idx.end());

    ll aa = idx[0].first, l = idx[0].second, r = idx[0].second, maxSum = 0;

    std::vector<ll> indices;
    for(ll i = 0; i < n; i++){
        indices.push_back(idx[i].second);

        if(i == n - 1 || idx[i].first != idx[i + 1].first){
            kadane(idx[i].first, indices, maxSum, l, r, aa);
            indices.clear();
        }

    }

    std::cout << aa << " " << l << " " << r << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();
    return 0;

}