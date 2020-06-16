//AE00 - Rectangles
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
	ll n;
	ll sum = 0;
	cin >> n;
	for(ll i = 1; i*i <= n; i++) {
		sum += n / i - i + 1;
	}
	cout << sum << endl;
}
