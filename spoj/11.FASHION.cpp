
//FASHION - Fashion Shows
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main () {
	ll t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<ll>f1;
		vector<ll>f2;
		ll temp;
		ll sum = 0;
		for(ll i = 0; i < n; i++) {
			cin >> temp;
			f1.push_back(temp);
		}
		for(ll i = 0; i < n; i++) {
			cin >> temp;
			f2.push_back(temp);
		}
		sort(f1.begin(), f1.end());
		sort(f2.begin(), f2.end());
		for(ll i = 0; i < n; i++) {
			sum += (f1[i] * f2[i]);
		}
		cout << sum << "\n";

	}
}
