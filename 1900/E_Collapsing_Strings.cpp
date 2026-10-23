#include <iostream>
#include <vector>

using ll = long long;

struct trie{
    struct node{
        ll next[26] = {};
        ll cnt;
    };

    std::vector<node> nodes;
    
    trie() {nodes.emplace_back();};

    void insert(const std::string &s){
        ll curr = 0;
        for(char ch : s){
            ll c = ch - 'a';
            if(nodes[curr].next[c] == 0){
                nodes[curr].next[c] = nodes.size();
                nodes.emplace_back();
            }

            curr = nodes[curr].next[c];
            nodes[curr].cnt++;
        }
    }

    ll query(const std::string &s){
        ll curr = 0, res = 0;
        for(ll i = s.size() - 1; i >= 0; i--){
            ll c = s[i] - 'a';
            if(nodes[curr].next[c] == 0) break;
            curr = nodes[curr].next[c];
            res += nodes[curr].cnt;
        }

        return res;
    }

};

void solve(){
    ll n; std::cin >> n;
    std::vector<std::string> arr(n);
    ll total = 0;
    for(ll i = 0; i < n; i++) {
        std::cin >> arr[i];
        total += arr[i].size();
    }

    trie t;
    t.nodes.reserve(total + 1);

    for(ll i = 0; i < n; i++) t.insert(arr[i]);

    ll ans = 2LL * total * n;
    for(ll i = 0; i < n; i++) ans -= 2LL * t.query(arr[i]);

    std::cout << ans << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;

}