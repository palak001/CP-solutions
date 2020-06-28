//CEQU - Crucial Equation
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
	if(b == 0)
		return a;
	else return gcd(b, a % b);
}

int main () {
	ll t, a, b, c;
	cin >> t;
	for(ll i = 1; i <= t; i++) {
		cout << "Case " << i << ": ";
		cin >> a >> b >> c;
		if(c % gcd(a, b)) 
			cout << "No" << endl;
		else 
			cout << "Yes" << endl;
	}
	
}
