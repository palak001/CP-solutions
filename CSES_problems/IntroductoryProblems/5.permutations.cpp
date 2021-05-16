#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
	ll n;
	cin >> n;
	if(n == 1)
		cout << 1 << endl;
	else if(n < 4) {
		cout << "NO SOLUTION" << endl;
	}
	else {
		ll start = 2, end = n;
		for(ll i = 1; i <= n; i++) {
			if(i == n-1) cout << 1 << " ";
			else {
				if(i % 2 == 1)
					cout << start++ << " ";
				else 
					cout << end-- << " ";
			}
		}
	}
}
