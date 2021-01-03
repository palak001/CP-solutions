#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		vector<int>a(n);
		int check, flag = 0;
		/* Checking if the sequence is already in a sorted order. */
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if(i == 0) {
				check = a[i];
			}
			else {
				if(a[i] < check)
					flag = 1;
				check = a[i];
			}
		}
		/* Sequence already sorted */
		if(flag == 0) {
			cout << 0 << endl;
			continue;
		}
		
		/*Finding an index having value greater than x and simulateously checking if the values less than x are sorted */
		int ind;
		check = a[0];
		flag = 0;
		for(ind = 0; a[ind] < x && ind < n; ind++) {
			if(check > a[ind]) {
				flag = 1;
				break;
			}
			check = a[ind];
		}
		if(ind == n) {
			cout << -1 << endl;
			continue;
		}
		
		
		int ans = 0, val, ans2 = 0;
		if(ind == 0) val = INT_MIN;
		else val = a[ind-1];
		flag = 0;
		for(; ind < n; ind++) {
			if(a[ind] < val) {
				flag = 1;
				break;
			}
			else if(a[ind] > x){
				val = x;
				x = a[ind];
				ans++;
			}
			else if(a[ind] == x) {
				val = x;
			}
			else {
				ans2 += ans;
				val = a[ind];
				ans = 0;
			}
		}
		if(flag == 1)
			cout << -1 << endl;
		else {
			cout << ans2 << endl;
		}
	}
}
