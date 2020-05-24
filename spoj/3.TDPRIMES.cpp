#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main () {
	ll n = 1e8;
	//finding prime numbers upto 10^4;
	vector<bool>is_prime(1e4+1, true);
	vector<ll>primes;
	is_prime[0] = is_prime[1] = false;
	for(ll i = 2; i <= 1e4; i++) {
		if(is_prime[i]) {
			primes.push_back(i);
			for(ll j = i * i; j <= 1e4; j+=i) {
				is_prime[j] = false;
			}
		}
	}

	ll count = 1;
	ll s = 1e4;
	
	for(ll k = 0; k * s <= n; k++) {
		vector<ll>range(s, true);
		ll start = k * s;
		for(auto p : primes) {
			ll rem = start % p;
			ll j;
			if(rem)
				j = p - rem;
			else
				j = rem;
			for(; j < s; j += p) {
				if(j + start == p) 
					continue;
				range[j] = false;
			}
		}
		if(start == 0) 
			range[0] = range[1] = false;
		for(ll i = 0; i < s && start + i <= n; i++) {
			if(range[i]){
				if(count%100 == 1) {
					cout << i + start << "\n";
				}
				count++;
			}	
		}
	}

}