#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll ans;
ll cnt[100005];
ll memo[100005];

ll f(ll a) {
	if(memo[a] != -1)
		return memo[a];
	if(a == 1 || a == 0)
		return memo[a] = cnt[a];
	return memo[a] = max(f(a-1), a * cnt[a] + f(a-2));
}

void solve(ll a[]) {
	for(ll i = 0; i < n; i++) {
		ans = max(ans, f(a[i]));
		// cout << "a[i]: " << a[i] << " i: " << i << " ans: " << ans << " f(a[i]): " << f(a[i]) << endl;
	}
}

int main() {
	cin >> n;
	ll a[n];
	ll j = 0;
	for(ll i = 0; i < 100005; i++) memo[i] = -1;
	for(ll i = 0; i < n; i++) {
		ll temp;
		cin >> temp;
		if(cnt[temp] == 0) {
			a[j++] = temp;
		}
		cnt[temp]++;
	}
	sort(a, a+j);
	n = j;
	solve(a);
	cout << ans << endl;
}
