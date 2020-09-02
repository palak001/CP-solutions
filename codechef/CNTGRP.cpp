#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll binPow(ll a, ll n) {
    if(n == 0)
        return 1;
    if(a == 1)
        return 1;
    ll r = binPow(a, n/2) % mod;
    if(n % 2 == 0)
        return (r * r) % mod;
    else return ((r * r) % mod * a % mod) % mod;
}

ll minv(ll a) {
    return binPow(a, mod - 2);
}

int main() {
    ll t, n, m;
    cin >> t; 
    while(t--) {
        cin >> n >> m;
        ll ar[n-1];
        for(ll i = 0; i < n-1; i++)
            cin >> ar[i];
        sort(ar, ar+(n-1));
        ll cnt[n];
        memset(cnt, 0, sizeof(cnt));
        cnt[0] = 1;
        ll ans = 1;
        for(ll i = 0; i < n-1; i++) {
            ans = (ans * cnt[ar[i]-1]) % mod;
            cnt[ar[i]]++;
        }
        
        // count pairs
        ll pairs = 0;
        for(ll i = 0; i < n; i++) {
            pairs += (cnt[i] * (cnt[i] - 1)) / 2;
        }
        ll x = m - n + 1, temp = 1;
        if(pairs < x)
            ans = 0;
        else {
            // calculating pairs!/(pairs - x)!
            for(ll i = pairs - x + 1; i <= pairs; i++)
                temp = (temp * i) % mod;
            
            // calculating (1/x!)%mod 
            for(ll i = 1; i <= x; i++) {
                temp = (temp * minv(i)) % mod;
            }
            ans = (ans * temp) % mod;
        }
        
        cout << ans << endl;
    }
}
