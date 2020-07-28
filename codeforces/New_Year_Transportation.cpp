include<bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main () {
	// n : no. of cells
	// t : cell no. you want to reach
	ll n, t;
	cin >> n >> t;
	vector<ll>a(n);
	for(ll i = 1; i < n; i++) {
		cin >> a[i];
	}
	vector<ll>adj(n+1);
	for(ll i = 1; i <= n; i++) {
		adj[i] = i+a[i];
	}
	adj[n] = 0;
	ll s = 1;
	ll i = 1;
	while(s != t) {
		s = adj[s];
		if(adj[n] == s)
			break;
	}
	if(s != t)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	
}
