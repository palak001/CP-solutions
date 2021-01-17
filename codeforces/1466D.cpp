//1466D - 13th Labour of Heracles
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		priority_queue<pair<ll, ll>>pq;
		vector<pair<ll, ll>>v;
		ll sum = 0;
		for(ll i = 0; i < n; i++) {
			ll temp;
			cin >> temp;
			sum += temp;
			v.push_back({temp, 0});
		}
		for(ll i = 0; i < n-1; i++) {
			int u, w;
			cin >> u >> w;
			v[u-1].second++;
			v[w-1].second++;
		}
		for(ll i = 0; i < n; i++) {
			pq.push({v[i].first, v[i].second});
		}
		// while (!pq.empty()) {
		// 	pair<ll, ll>t = pq.top();
		// 		cout << "t: " << t.first << " " << t.second << endl;
	 //       pq.pop();
	 //   }
		
		cout << sum << " ";
		pair<ll, ll>t;
		if(!pq.empty())
			t = pq.top();
		for(ll i = 2; i <= n-1; i++) {
			if(pq.empty()) {
				cout << sum << " ";
			}
			else {
				while(t.second <= 1 && !pq.empty()) {
					pq.pop();
					t = pq.top();
				}
				if(pq.empty()) {
					cout << sum << " ";
				}
				else {
					sum += t.first;
					t.second--;
					cout << sum << " ";
				}
			}
		}
		cout << endl;
	}
	
}
