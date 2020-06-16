// ACPC10A - What’s Next
#include<bits/stdc++.h>
typedef long double ll;
using namespace std;

int main () {
	ll a, b, c;
	cin >> a >> b >> c;
	
	while(a || b || c) {
		ll sum = a + b + c;
		if(sum == 3 * (a + c)/2) {
			cout << "AP " << c + b - a;
		}
		else {
			cout << "GP " << c * b/a;
		}
		cin >> a >> b >> c;
		if(a || b || c) 
			cout << "\n";
	}
}
