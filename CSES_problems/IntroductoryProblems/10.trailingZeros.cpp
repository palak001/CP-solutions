#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	ll d = 5, ans = 0;
	while(n >= d) {
		ans += n/d;
		d *= 5;
	}
	cout << ans << endl;	
}
