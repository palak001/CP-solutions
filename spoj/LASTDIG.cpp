// LASTDIG - The last digit
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
	ll t, a, b;
	ll ar[11] = {0, 1, 4, 4, 2, 1, 1, 4, 4, 2, 1};
	cin >> t;
	while(t--) {
		cin >> a >> b;
		if(a == 0) {
			cout << 0 << endl;
			continue;
		}
		if(b == 0) {
			cout << 1 << endl;
			continue;
		}
		ll la = a % 10;
		if(la == 0)
			la = 10;
		ll rem = b % ar[la];
		if(rem == 0)
			rem = ar[la];
		ll p = 1;
		for(ll i = 0; i < rem; i++)
			p *= a;
		cout << p % 10 << endl;
	}
}
