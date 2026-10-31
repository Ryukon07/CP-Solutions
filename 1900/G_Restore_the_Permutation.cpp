    #include <iostream>
    #include <vector>
    #include <set>

    using ll = long long;

    void solve(){
        ll n; std::cin >> n;
        ll m = n / 2;

        bool ok = true;
        std::vector<ll> b(m), used(n + 1, 0);
        for(ll i = 0; i < m; i++){
            std::cin >> b[i];
            if(used[b[i]]) ok = false;
            used[b[i]] = 1;
        }

        if(!ok){
            std::cout << -1 << "\n";
            return;
        }

        std::set<ll> available;
        std::vector<ll> a(n);

        for(ll i = 1; i <= n; i++) if(!used[i]) available.insert(i);

        for(ll i = m - 1; i >= 0; i--){
            auto it = available.lower_bound(b[i]);
            if(it == available.begin()){
                std::cout << -1 << "\n";
                return;
            }

            --it;
            a[2 * i] = *it;
            a[2 * i + 1] = b[i];

            available.erase(it);
        }

        for(ll i = 0; i < n; i++) std::cout << a[i] << " ";
        std::cout << "\n";

    }

    int main(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

        ll t; std::cin >> t;
        while(t--) solve();

    }