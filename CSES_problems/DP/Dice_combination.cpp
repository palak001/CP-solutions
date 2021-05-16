#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

int main() {
	ll n;
	cin >> n;
	vector<ll>dp(n+1, 0);
	dp[0] = 1;
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= 6; j++) {
			if(i >= j) {
				dp[i] = (dp[i] + dp[i-j]) % mod;
			}
			else break;
		}
	}
	
	// for(ll i = 0; i < n+1; i++)
	// 	cout << dp[i] << " ";
	// cout << endl;
	
	cout << dp[n] << endl;
}
