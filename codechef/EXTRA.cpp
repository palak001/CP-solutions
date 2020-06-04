//given a x, find the number of pair(i, j) such that a[i]+b[j] <= x
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int binSearch(int l, int r, int v, int ar[]) {
	int ans = -1;
	int m;
	while(l <= r) {
		m = l + (r - l) / 2;
		if(ar[m] <= v){
			ans = max(m, ans);
			l = m + 1;
		}
		else 
			r = m - 1;
	}
	
	return ans + 1;
}

int main () {
	int a[10];
	int b[10];
	for(int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < 10; i++) {
		cin >> b[i];
	}
	int x;
	cin >> x;
	int l;
	int result = 0;
	for(int i = 0; i < 10; i++) {
		l = x - a[i];
		result += binSearch(0, 10, l, b);	
	}
	cout << result << endl;
}
