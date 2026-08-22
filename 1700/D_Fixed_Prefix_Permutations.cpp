#include <iostream>
#include <vector>

using ll = long long;

struct trieNode{
    trieNode* children[11];
    trieNode(){
        for(int i = 0; i < 11; ++i) children[i] = nullptr;
    }
};

trieNode* insert(trieNode* root, std::vector<ll>& a){
    trieNode* node = root;
    for(ll i = 0; i < a.size(); ++i){
        if(node->children[a[i]] == nullptr) node->children[a[i]] = new trieNode();
        node = node->children[a[i]];
    }
    return node;
}

void query(trieNode* root, std::vector<ll>& a, ll& ans){
    trieNode* node = root;
    for(ll i = 0; i < a.size(); ++i){
        if(node->children[a[i]] == nullptr) break;
        node = node->children[a[i]];
        ans++;
    }
}

void deleteTrie(trieNode* root){
    for(int i = 0; i < 11; ++i){
        if(root->children[i] != nullptr) deleteTrie(root->children[i]);
    }
    delete root;
}

void solve(){
    ll n, m; std::cin >> n >> m;
    std::vector<std::vector<ll>> a(n, std::vector<ll>(m));
    std::vector<std::vector<ll>> idx(n, std::vector<ll>(m));

    trieNode* root = new trieNode();

    for(ll i = 0; i < n; ++i){
        for(ll j = 0; j < m; j++) std::cin >> a[i][j];
        for(ll j = 0; j < m; j++) idx[i][a[i][j] - 1] = j + 1;
        insert(root, idx[i]);
    }

    for(ll i = 0; i < n; ++i){
        ll ans = 0;
        query(root, a[i], ans);
        std::cout << ans << (i == n - 1 ? "" : " ");
    }

    std::cout << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}