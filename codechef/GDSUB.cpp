#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

int main () {
    ll n, k;
    cin >> n >> k;
    ll dist = 0;
    vector<ll>cnt;
    ll count = 0;
    ll ar[n];
    for(ll i = 0; i < n; i++)
        cin >> ar[i];
        
    sort(ar, ar + n);
    ll p = ar[0];
    count = 1;
    for(ll i = 1; i < n; i++) {
        if(ar[i] == p) {
            count++;
        }
        else {
            cnt.push_back(count);
            count = 1;
            p = ar[i];
        }
    }
    cnt.push_back(count);
    k = min(k, (ll)1007);
    ll ans = 1;
    vector<ll>cumulative(cnt.size());
    count = 0;
    cumulative[0] = cnt[0];
    for(ll i = 0; i < cnt.size(); i++) {
        ans += cnt[i];
        ans %= mod;
        if(i!=0)
            cumulative[i] = (cumulative[i-1] + cnt[i])%mod;
    }    
    ll temp[cumulative.size()];
    for(ll i = 2; i <= k; i++) {
        ll j;
        for(j = i; j <= cumulative.size(); j++) {
            ans += cumulative[j - 2] * cnt[j - 1];
            ans %= mod;
            temp[j-1] = (cumulative[j - 2] * cnt[j - 1])%mod;
        }
        if(i < cumulative.size())
            cumulative[i-1] = temp[i-1];
        for(ll k = i; k < cumulative.size(); k++)
            cumulative[k] = (cumulative[k-1] + temp[k])%mod;
        
    }
    cout << ans << endl;
}
