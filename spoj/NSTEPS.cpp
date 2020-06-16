#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main () {
	ll n;
	cin >> n;
	while(n--){
		ll x, y;
		ll a, d = 4, term, r;
		cin >> x >> y;
		if(x == y || x - y == 2) {
			r = x % 2;
			if(x - y == 2) {
				if(r == 0) {
					a = 2;
				}
				else {
					a = 3;	
				}
				term = a + (x/2 - 1) * d;
				cout << term << "\n";
			}
			else {
				if(r == 0) {
					a = 4;
				}
				else 
					a = 5;
				term = a + (x/2 - 1) * d;
				cout << term << "\n";
			}
		}
		else 
			cout << "No Number\n";
	}
}
