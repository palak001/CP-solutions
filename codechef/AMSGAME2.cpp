#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll v[62];
ll ans = 0, n;
ll dp[62][10002];
ll binPow(ll a, ll n) {
    if(n == 0 || a == 1)
        return 1;
    if(n == 1)
        return a;
    ll r = binPow(a, n / 2);
    if(n % 2 == 0)
        return r * r;
    else 
        return r * r * a;
}

ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

ll c1, c2;
ll countSub(ll pos, ll current_gcd) {
    c1++;
    if(pos == n) {
        if(current_gcd == 1)
            return 1;
        else 
            return 0;
    }
    if(dp[pos][current_gcd] != -1) {
        return dp[pos][current_gcd];
    }
    else {
        c2++;
        return dp[pos][current_gcd] = countSub(pos + 1, current_gcd) + countSub(pos + 1, gcd(current_gcd, v[pos]));;
    }
}

void solve() {
    for(ll i = 0; i < n; i++) {
        ans += countSub(i+1, v[i]);
    }
}


int main() {
    ll t;
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> n;
        for(ll i = 0; i < 62; i++) {
            v[i] = 0;
            for(ll j = 0; j < 10002; j++)
                dp[i][j] = -1;
        }
        for(ll i = 0; i < n; i++) {
            cin >> v[i];
        }
        solve();
        cout << ans << endl;
    }
}
