#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binPow(ll a, ll n) {
    if(n == 0 || a == 1) return 1;
    ll res = binPow(a, n/2);
    if(n % 2 == 1)
        return res * res * a;
    else 
        return res * res;
}

ll shift(ll n) {
    ll res = 1;
    while(n--) {
        res = res << 1;
    }
    return res;
}


int main() {
    ll t, n, x;
    ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> x;
        ll ar[n];
        /* filled the array */
        for(ll i = 0; i < n; i++) {
            cin >> ar[i];
        }
        ll i = 0;
        while(i < n - 1 && x > 0) {
            if(ar[i] == 0) {
                i++;
                continue;
            }
            ll power = shift(log2(ar[i]));
            ar[i] = ar[i] ^ power;
            
            x--;
            ll j;
            for(j = i + 1; j < n; j++) {
                if(ll(ar[j] ^ power) < ar[j]) {
                    ar[j] = ar[j] ^ power;
                    break;
                }
            }
            if(j == n) {
                ar[n-1] = power ^ ar[n-1];
            }
        }
        if(x > 0) {
            if(x==1 || (x % 2 == 1 && n == 2)) {
                ar[n-2] = ar[n-2] ^ 1;
                ar[n-1] = ar[n-1] ^ 1;
            }
        }
        
        for(i = 0; i < n; i++) {
            cout << ar[i] << " ";
        }
    }
}
