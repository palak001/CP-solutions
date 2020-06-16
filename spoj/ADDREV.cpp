#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main () {
	ll n;
	cin >> n;
	while(n--) {
		ll a, b, sum = 0, ta = 0, tb = 0, tsum = 0;
		cin >> a >> b;
		while(a) {
			ta = 10 * ta + a % 10;
			a /= 10;
		}
		while(b) {
			tb = 10 * tb + b % 10;
			b /= 10;
		}
		sum = ta + tb;
		while(sum) {
			tsum = 10 * tsum + sum % 10;
			sum /= 10;
		}
		cout << tsum << "\n";
	}
}
