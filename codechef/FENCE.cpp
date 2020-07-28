// FENCE
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}

int main () {
    ll t;
    std::ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<pair<ll, ll> >v(k);
        vector<pair<ll, ll> >v1(k);
        for(ll i = 0; i < k; i++) {
            cin >> v[i].first >> v[i].second;
            v1[i].second = v[i].first;
            v1[i].first = v[i].second;
        }
        
        sort(v.begin(), v.end(), comp);
        sort(v1.begin(), v1.end(), comp);
        ll count = 0, tcount = 0;
        for(ll i = 0; i < k - 1; i++) {
            ll j = i + 1;
            if(v[i].first == v[j].first && abs(v[i].second - v[j].second) == 1)
                count++;
        }
        for(ll i = 0; i < k - 1; i++) {
            ll j = i + 1;
            if(v1[i].first == v1[j].first && abs(v1[i].second - v1[j].second) == 1)
                count++;
        }
        cout << 4 * k - 2 * count << endl;
    }
}
