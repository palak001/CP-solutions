#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll prefix[100001][6];
ll kp[100001];
ll prime[100001];

void kPrime() {
    prime[0] = prime[1] = 1;
    for(ll i = 2; i < 100001; i++) {
        if(!prime[i]) {
            for(ll j = i; j < 100001; j+=i) {
                kp[j]++;
                prime[j] = 1;
            }
        }
    }
}

void precompute() {
    kPrime();
    prefix[2][1] = 1;
    prefix[2][2] = prefix[2][3] = prefix[2][4] = prefix[2][5] = 0;
    for(ll i = 3; i <= 100000; i++) {
        for(ll k = 1; k <= 5; k++) {
            prefix[i][k] = prefix[i-1][k] + (kp[i] == k);
        }
    }
}

int main () {
    ll t, a, b, k;
    cin >> t;
    precompute();
    while(t--) {
        cin >> a >> b >> k;
        cout << prefix[b][k] - prefix[a-1][k] << "\n";
    }
}
