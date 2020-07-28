#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
bool comp(pair<ld, ll>a, pair<ld, ll>b) {
	return a.first < b.first;
}
 
int main () {
	ll n;
	cin >> n;
	vector<pair<ld, ll> >ang(n);
	for(ll i = 0; i < n; i++) {
		ll x, y;
		ld tang;
		cin >> x >> y;
		tang = atan2(1.0 * y, 1.0 * x);
		ang[i].first = tang;
		ang[i].second = i;
	}
	sort(ang.begin(), ang.end(), comp);
	ld smal = 1e10;
	ll x, y;
	for(ll i = 0; i < n; i++) {
		ld temp = ang[(i+1) % n].first - ang[i].first;
		if(temp < 0)
			temp += 2*acos(-1);
		if(temp < smal) {
			smal = temp;
			x = ang[i].second; y = ang[(i+1)%n].second;
		}
	}
	cout << x+1 << " " << y+1 << endl;
}
