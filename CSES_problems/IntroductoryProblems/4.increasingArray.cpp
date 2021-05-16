#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
	ll n;
	cin >> n;
	vector<ll>v(n);
	for(ll i = 0; i < n; i++) cin >> v[i];
	ll lar = v[0], ans = 0;
	for(ll i = 1; i < n; i++) {
		if(v[i] < lar) {
			ans += lar - v[i];
		}
		else lar = v[i];
	}
	cout << ans << endl;
