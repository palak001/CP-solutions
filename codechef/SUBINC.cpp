#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    ll t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<ll>ar(n), v(n);
        for(ll i = 0; i < n; i++) 
            cin >> ar[i];
        v[0] = 1;
        ll sum = 1;
        for(ll i = 1; i < n; i++) {
            if(ar[i] >= ar[i-1]) {
                v[i] = v[i-1] + 1;
            }
            else v[i] = 1;
            sum += v[i];
        }
        cout << sum << endl;
    }
}
