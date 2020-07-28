// AGGRCOW - Aggressive cows
// #binary-search
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dis[100001];
ll t, n, c, ans = INT_MIN;

// counts number of cows for some minimum distance.
ll countCows(ll min) {
	ll count = 1, i = 1, prev = dis[i];
	while(i <= n) {
		if(abs(dis[i] - prev) >= min) {
			count++;
			prev = dis[i];
		}
		else
			i++;
	}
	return count;
}

// maximizes the minimum distance between the cows.
void findMin(ll low, ll high) {
	while(low <= high) {
		ll mid = low + (high - low) / 2;
		ll maxCows = countCows(mid);
		if(maxCows >= c) {
			ans = max(ans, mid);
		}
		if(maxCows >= c)
			low = mid+1;
		else high = mid - 1;
	}
}

int main () {
	cin >> t; 
	while(t--) {
		ans = INT_MIN;
		cin >> n >> c;
		for(ll i = 1; i <= n; i++) 
			cin >> dis[i];
		sort(dis, dis+n);
		findMin(dis[1], dis[n]);
		cout << ans << endl;
	}
}
