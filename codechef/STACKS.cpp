//STACKS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
	ll t, n, temp;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<ll>v(1, INT_MAX);
		while(n--) {
			cin >> temp;
			if(v[v.size() - 1] <= temp) {
				v.push_back(temp);
			}
			else {
				vector<ll>::iterator upper = upper_bound(v.begin(), v.end(), temp);
				v[upper - v.begin()] = temp;
			}
		}
		cout << v.size() << " ";
		for(auto i:v) {
			cout << i << " ";
		}
		cout << "\n";
	}
}
