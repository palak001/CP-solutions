#include<bits/stdc++.h>
using namespace std;

int t, n;
string s;

void turnOver(int l, int r) {
	while(l < r) {
		char ch = s[l];
		s[l] = s[r];
		s[r] = ch;
		l++;
		r--;
	}
}

int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		cin >> s;
		int ans = 0;
		for(int i = 1; i < n-1; i++) {
			if(s[i] == s[i-1]) {
				// find good substring;
				int j = i+1;
				char first = s[j], second;
				int len = 1;
				for(j = i+1; j < n; j++) {
					if(s[j] == s[j+1] && s[j] != s[i]) {
						break;
					}
				}
				if(i < j) {
					turnOver(i, j);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}
