#include <iostream>
#include <vector>

using ll = long long;

void solve(){
    ll n, k, q; std::cin >> n >> k >> q;
    std::vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        std::cin >> a[i];
        a[i] = a[i] - i;
    }

    ll offset = n + 5;
    std::vector<ll> freq(2 * n + 10, 0), cnt(k + 1, 0);

    ll max = 0;
    std::vector<ll> ans(n);

    for(ll i = 0; i < k; i++){
        ll val = a[i] + offset;
        cnt[freq[val]]--;
        freq[val]++;
        cnt[freq[val]]++;
        max = std::max(max, freq[val]);
    }

    ans[0] = k - max;

    for(ll i = k; i < n; i++){
        ll left = a[i - k] + offset;
        cnt[freq[left]]--;
        if(freq[left] == max && cnt[freq[left]] == 0) max--;
        freq[left]--;
        cnt[freq[left]]++;

        ll right = a[i] + offset;
        cnt[freq[right]]--;
        freq[right]++;
        cnt[freq[right]]++;

        if(freq[right] > max) max = freq[right];

        ans[i - k + 1] = k - max;
    }

    for(ll i = 0; i < q; i++){
        ll l, r; std::cin >> l >> r;
        l--; r--;
        std::cout << ans[l] << "\n";
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t; std::cin >> t;
    while(t--) solve();

}