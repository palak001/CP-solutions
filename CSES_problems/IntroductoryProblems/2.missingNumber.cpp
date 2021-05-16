#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	ll ans = 0;
	for(ll i = 1; i <= n; i++) ans ^= i;
	for(ll i = 0; i < n-1; i++) {
		ll t;
		cin >> t;
		ans ^= t;
	}
	cout << ans << endl;
}
