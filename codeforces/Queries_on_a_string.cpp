#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
	string s;
	cin >> s;
	ll l, r, k, m;
	cin >> m;
	while(m--) {
		cin >> l >> r >> k;	
		if(k % (r - l + 1) == 0) {
			continue;
		}
		else {
			k = k % (r - l + 1);
			vector<char>v;
			for(ll i = r - k + 1; i <= r; i++) {
				v.push_back(s[i-1]);
			}
			for(ll i = r - 1, j = i - k; j >= l-1; i--, j--) {
				s[i] = s[j];
			}
			for(ll i = 1; i <= v.size(); i++) {
				s[l + i - 2] = v[i-1];
			}
		}
	}
	cout << s << endl;
}

