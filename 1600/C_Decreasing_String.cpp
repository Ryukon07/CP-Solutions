#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using ll = long long;

void solve(){
    std::string s; std::cin >> s;
    ll pos; std::cin >> pos;

    ll n = s.size();

    std::vector<ll> prefixSum(n, 0);
    prefixSum[0] = n;
    for(ll i = 1; i < n; i++){
        ll tmp = n - i;
        prefixSum[i] = prefixSum[i - 1] + tmp;
    }

    ll idx = std::upper_bound(prefixSum.begin(), prefixSum.end(), pos - 1) - prefixSum.begin();

    std::stack<char> st;
    st.push(s[0]);

    ll removed = 0;
    for(ll i = 1; i < n; i++){
        while(!st.empty() && st.top() > s[i] && removed < idx){
            st.pop();
            removed++;
        }
        st.push(s[i]);
    }
    while(removed < idx){
        st.pop();
        removed++;
    }

    std::string ans;
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    std::reverse(ans.begin(), ans.end());

    ll rem = (idx == 0 ? pos - 1: pos - prefixSum[idx - 1] - 1);

    std::cout << ans[rem];

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}