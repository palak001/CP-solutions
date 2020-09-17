#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, l, s;
ll dp[53][1400][53];

int main() {
    cin >> t;
    for(ll i = 0; i < 53; i++) {
        dp[0][0][i] = 1;
    }
    
    // length of the desired string
    for(ll i = 1; i < 53; i++) {
        // sum(hash value) of the desired string
        for(ll j = 1; j < 1400; j++) {
            // count of string of length i and sum j upto index k
            for(ll k = 1; k < 53; k++) {
                    if(j-k >= 0) {
                        dp[i][j][k] += dp[i-1][j-k][k-1];
                    }
                    dp[i][j][k] += dp[i][j][k-1];
            }
        }
    }
    
    ll c = 0;
    while(t--) {
        c++;
        cin >> l >> s;
        if(l > 52 || s > 1378) {
            cout << "Case " << c << ": 0" << endl;
            continue;
        }
        cout << "Case " << c << ": " << dp[l][s][52] << endl;
    }
}
