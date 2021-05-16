#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	ll sum = (n * (n + 1)) / 2;
	if(sum % 2 == 1)
		cout << "NO" << endl;
	else {
		vector<ll>set1, set2;
		ll half = sum / 2;
		ll i;
		for(i = n; i >= 1; i--) {
			if(half <= 0) break;
			if(half >= i) {
				set1.push_back(i);
				half -=i;
			}
			else {
				set2.push_back(i);
			}
		}
		for(; i >= 1; i--)
			set2.push_back(i);
		cout << "YES" << endl;
		cout << set1.size() << endl;
		for(auto i:set1)
			cout << i << " ";
		cout << endl;
		cout << set2.size() << endl;
		for(auto i:set2)
			cout << i << " ";
	}
}
