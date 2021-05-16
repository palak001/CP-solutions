#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	ll ans = 1, current = 1;
	char prev = s[0];
	for(ll i = 1; i < s.length(); i++) {
		if(s[i] == s[i-1]) {
			current++;
		}
		else {
			ans = max(ans, current);
			prev = s[i];
			current = 1;
		}
	}
	ans = max(ans, current);
	cout << ans << endl;
}
