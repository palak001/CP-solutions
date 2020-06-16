//LOCKER - Magic of the locker
#include<bits/stdc++.h>
typedef long long ll;
#define M 1000000007
using namespace std;

ll binPow(ll a, ll n) {
	if(n == 0)
		return 1;
	if(n == 1)
		return a%M;
	ll r = binPow(a, n/2);
	if(n % 2 == 0) {
		return (r%M * r%M)%M;
	}
	else 
		return (r%M * r%M * a%M)%M;
}

int main () {
	ll t, n;
	cin >> t;
	while(t--) {
		ll ans, n1;
		cin >> n;
		if(n < 3) {
			cout << n << endl;
			continue;
		}
		if(n%3 == 1) {
			n1 = (n - 4) / 3;
			ans = 4*binPow(3, n1);
		}
		else if(n%3 == 2){
			n1 = (n - 2) / 3;
			ans = 2*binPow(3, n1);
		}
		else 
			ans = binPow(3, n/3);
		ans %= M;
		cout << ans << endl;
	}
	
}
