#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t, n, k;
    cin >> t;
    while(t--) {
        ll ss = 0;
        cin >> n >> k;
        ll color[n+1];
        for(ll i = 0; i <= n; i++) {
            cin >> color[i];
        }
        set<pair<ll, ll>>s;
        for(ll i = 0; i <= n; i++) {
            ss += color[i];
            s.insert({color[i], i});
        }
        assert(ss == n*k);
        for(ll i = 0; i < n; i++) {
            ll a = (*s.begin()).first, b = (*s.begin()).second;
            s.erase(s.begin());
            ll diff = k - a;
            cout << b << " " << a << " ";
            
            auto it = s.end();
            it--;
            a = (*it).first; b = (*it).second;
            cout << b << " " << diff << "\n";
            a -= diff;
            s.erase(it);
            s.insert({a, b});
        }
    }
}
