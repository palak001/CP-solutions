//EURON

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
	ll n, x;
	cin >> n;
	ll sum = 0;
	vector<ll>v;
	for(ll i = 0; i < n; i++) {
		cin >> x;
		vector<ll>::iterator upp = upper_bound(v.begin(), v.end(), x);
		sum += v.end() - upp;
		v.insert(upp, x);
	}
	cout << sum << endl;
}
