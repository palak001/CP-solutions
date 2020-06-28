//FLOW016
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll GCD(ll a, ll b) {
    if(b == 0)
        return a;
    return GCD(b, a % b);
}

int main () {
    ll t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        ll gcd = GCD(a, b);
        ll lcm = a / gcd * b;
        cout << gcd << " " << lcm << endl;
    }
    return 0;
}

