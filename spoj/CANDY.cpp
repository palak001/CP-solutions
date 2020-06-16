//CANDY - Candy I
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
	ll n;
	cin >> n;
	while(n != -1) {
		vector<ll>v;
		ll temp;
		ll sum = 0;
		ll tn = n;
		while(tn--) {
			cin >> temp;
			sum += temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());
		if(sum % n) {
			cout << -1;
		}
		else {
			ll av = sum / n;
			ll s = 0;
			for(ll i = 0; i < n; i++) {
				if(v[index] > av) {
					s += v[index] - av;
				}
			}
			cout << s;
		}
		cin >> n;
		// if(n != -1)
			cout << "\n";
	}
	
}

