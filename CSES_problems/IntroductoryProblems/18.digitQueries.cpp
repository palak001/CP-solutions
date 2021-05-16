#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

vector<ll>reference;

ll binPow(ll a, ll b) {
	ll res = 1;
	while(b > 0) {
		if(b % 2 == 1)
			res = res * a;
			
		a = a * a;
		b = b / 2;
	}
	return res;
}

void preprocessing() {
	ll nine = 9;
	for(ll i = 1; i <= 18; i++) { // i iterates over number of digits
		reference.push_back(nine*i);
		nine = nine*10;
	}
	
	// prefix sum
	for(ll i = 1; i < reference.size(); i++)
		reference[i] = reference[i] + reference[i-1];
}

int main() {
	preprocessing();
	ll q;
	cin >> q;
	// for(ll i = 0; i < reference.size(); i++) {
	// 	cout << reference[i] << " ";
	// }
	// cout << endl;
	while(q--) {
		ll k;
		cin >> k;
		ll ind = lower_bound(reference.begin(), reference.end(), k) - reference.begin();
		if(ind == 0) {
			cout << k << endl;
			continue;
		}
		if(ind >= 1) {
			k -= reference[ind-1];	
		}
		ll digits = ind+1;
		ll num = k / digits;
		ll rem = k % digits;
		if(digits >= 2) {
			num += binPow(10, digits-1);
		}
		ll ans;
		if(rem == 0) {
			ans = (num-1)%10;
		}
		else {
			ll temp = digits;
			while(temp != rem) {
				num = num / 10;
				temp--;
			}
			ans = num % 10;
		}
		cout << ans << endl;
	}
}
