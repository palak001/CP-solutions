// COINS - Bytelandian gold coins
#include<bits/stdc++.h>
using namespace std;

void precalculate(long long a[]) {
	long long i = 0;
	for(i = 0; i < 10001; i++) 
		a[i] = i;
	for(i = 0; i < 100001; i++) {
		a[i] = max(a[i], a[i/2] + a[i/3] + a[i / 4]);
	}
}

long long goldCoin(long long n, long long a[]) {
	if(n < 100000)
		return a[n];
	return max(n, goldCoin(n/2, a) + goldCoin(n/3, a) + goldCoin(n/4, a));
}

int main () {
	long long a[100001];
	precalculate(a);
	long long n;
	while(cin >> n) {
		long long max = goldCoin(n, a);
		cout << max << endl;
	}
}
