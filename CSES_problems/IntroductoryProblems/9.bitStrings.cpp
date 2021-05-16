#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

ll binPow(ll a, ll b) {
	ll ans = 1;
	while(b > 0) {
		if(b % 2 == 1)
			ans = (ans * a) % mod;
		b = b / 2;
		a = (a * a) % mod;
	}
	return ans;
}

int main() {
	ll n;
	cin >> n;
	cout << binPow(2, n) << endl;
}
