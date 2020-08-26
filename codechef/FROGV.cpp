#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(pair<ll, ll> a, pair<ll, ll>b) {
    return a.second <= b.second;
}

int main () {
    ll n, k, p;
    cin >> n >> k >> p;
    vector<pair<ll, ll>>v(n);
    for(ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        v[i] = {i+1, temp};
    }
    sort(v.begin(), v.end(), comp);
    map<ll, ll>m;
    ll group = 1;
    m.insert({v[0].first, 1});
    for(ll i = 1; i < n; i++) {
        if(v[i].second - v[i-1].second > k)
            group++;
        m.insert({v[i].first, group});
    }
    
    ll a, b;
    for(ll i = 0; i < p; i++) {
        cin >> a >> b;
        if(m[a] == m[b])
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }
}
