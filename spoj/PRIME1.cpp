// PRIME1 - Prime Generator
// using segmented sieve algorithm
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main () {
	ll t, l, r;
	cin >> t;
	while(t--) {
		cin >> l >> r;
		//finding prime no. upto sqrt of r
		ll size = sqrt(r);
		vector<ll>primes;
		vector<bool>is_prime(size + 1, true); 
		for(ll i = 2; i <= size; i++) {
			if(is_prime[i]) {
				primes.push_back(i);
				for(ll j = i*i; j <= size; j+=i) {
					is_prime[j] = false;
				}
			}
		}
		
		//using those primes to sieve the range
		vector<bool>range(r - l + 1, true);
		for(auto p : primes) {
			ll rem = l%p;   //remainder
			ll i;
			if(rem)
				i = p - rem;
			else 
				i = rem;
			for(; i <= r - l + 1; i+= p) {
				if(i == p - l)
					continue;
				range[i] = false;
			}
		}
		
		if(l == 1)
			range[0] = false;
		
		for(ll i = 0; i < r - l + 1; i++) {
			if(range[i]) {
				cout << l + i << "\n";
			}
		}
		if(t != 0) {
			cout << "\n";
		}
	}
}
