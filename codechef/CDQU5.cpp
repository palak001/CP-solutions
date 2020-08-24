#include<bits/stdc++.h>
#define M 1000000009
using namespace std;
typedef long long ll;

ll dp[1000005];

void precompute() {
    dp[0] = dp[1] = 0;
    dp[2] = dp[3] = 1;
    for(ll i = 4; i < 1000005; i++) {
        dp[i] = (dp[i-2]%M + dp[i-3]%M)%M;
    }
}

int main () {
    ll t, x;
    precompute();
    cin >> t;
    while(t--) {
        cin >> x;
        cout << dp[x] << endl;
    }
}
