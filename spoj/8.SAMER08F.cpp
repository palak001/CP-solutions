// SAMER08F - Feynman
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main () {
		ll n;
		cin >> n;
	while(n != 0) {
		cout << (n * (n+1) * (2*n+1)) / 6 << "\n";
		cin >> n;
	}
}
