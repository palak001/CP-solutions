// ZSUM - Just Add It
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll M = 10000007;
 
ll binPow(ll a, ll n) {
	if(n == 0)
		return 1;
	if(a == 0 || a == 1 || n == 1)
		return (a % M);
	ll r = binPow(a, n / 2) % M;
	if(n % 2 == 0)
		return (r % M * r % M) % M;
	else 
		return ((r % M * r % M) % M * a % M) % M;
}
 
 
int main () {
	ll n, k;
	ll ans;
	cin >> n >> k;
	while(n != 0 || k != 0) {
		ans = (2 * binPow(n - 1, k) + 2 * binPow(n - 1, n - 1) + binPow(n, k) + binPow(n, n)) % M;
		cout << ans << endl;
		cin >> n >> k;
	}
}
