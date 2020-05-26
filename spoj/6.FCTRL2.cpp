// FCTRL2 - Small factorials 
// #big-numbers
#include<bits/stdc++.h>
typedef long long ll;
#define MAX 500
using namespace std;

int main () {
	ll t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		ll result[MAX];
		ll res_size = 1;
		ll carry = 0;
		result[0] = 1;
		for(ll i = 2; i <= n; i++) {
			for(ll j = 0; j < res_size; j++) {
				ll product = result[j] * i + carry;
				result[j] = product % 10;
				carry = product / 10;
			}
			while(carry) {
				result[res_size] = carry % 10;
				carry /= 10;
				res_size++;
			}
		}
		
		for(ll i = res_size - 1; i >= 0; i--) {
			cout << result[i];
		}
		cout << "\n";
	}
}
