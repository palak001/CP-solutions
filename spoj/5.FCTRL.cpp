#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main () {
	ll t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		ll sum = 0;
		while(n) {
			sum += n / 5;
			n /= 5;
		}
		cout << sum << "\n";
	}
}
