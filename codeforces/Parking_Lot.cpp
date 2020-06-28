//Parking Lot
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll binPow(ll a, ll n) {
	if(a == 0 || a == 1 || n == 1)
		return a;
	if(n == 0)
		return 1;
	ll r = binPow(a, n/2);
	if(n % 2 == 0)
		return r * r;
	else 
		return r * r * a;
}

int main () {
	ll n;
	cin >> n;
	ll ans = 4 * 3 * binPow(4, n - 3) * 2 + 3 * 4 * 3 * binPow(4, n - 4) * (n - 3);
	cout << ans;
}
