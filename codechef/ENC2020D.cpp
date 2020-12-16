#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, q;

ll solve(ll m, ll d[]) {
	ll count = 1, i = 1, prev = 0;
	while(i < n && count < q) {
		if(d[i] - d[prev] >= m) {
			count++;
			prev = i;
		}
		i++;
	}
	return count;
}

int main() {
	cin >> n >> q;
	ll d[n];
	for(ll i = 0; i < n; i++)
		cin >> d[i];
	ll l, r, m;
	sort(d, d+n);
	l = 1; r = 1000000000;
	while(l <= r) {
		m = l + (r - l) / 2;
		ll count = solve(m, d);
		// cout << m << " " << count << endl;
		if(count >= q) {
			l = m + 1;
		}
		else 
			r = m - 1;
	}
	cout << r << endl;
}
