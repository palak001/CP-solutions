#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;

int main () {
    ll t, n, d;
    cin >> t;
    while(t--) {
        cin >> n >> d;
        ll ar[n];
        for(ll i = 0; i < n; i++) 
            cin >> ar[i];
        sort(ar, ar+n);
        lld l = 0, r = 2e9;
        for(ll i = 0; i < 70; i++) {
            // possible ans
            lld m = l + (r - l)/2;
            lld shooting = ar[0] + m;
            ll j;
            // cout << l << " " << m << " " << r << endl;
            for(j = 1; j < n; j++) {
                if(ar[j] + d < shooting) {
                    r = m;
                    break;
                }
                else {
                    shooting = max(shooting, (lld)ar[j]) + m;
                }
            }
            if(j == n) {
                l = m;
            }
        }
        cout << fixed << setprecision(8) << l << endl;
    }
}
