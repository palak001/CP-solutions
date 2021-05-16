#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; i++) {
		// total ways to place two knights 
		ll tot_ways = (i*i)*(i*i - 1) / 2; // see how similar it is to i(i-1)/2 i.e the number 
										  // of substrings in a string. 
		// number of ways to place two knights so that they attack eachother.
		ll attack_ways = 	4*(i - 1)*(i - 2);
		cout << tot_ways - attack_ways << endl;	
	}
}
