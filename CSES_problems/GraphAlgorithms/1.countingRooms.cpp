#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(vector<vector<pair<ll, ll>>>&adj, ll r, ll c) {
	adj[r][c].second = 1;
	vector<pair<ll, ll>>direction {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	for(ll i = 0; i < direction.size(); i++) {
		ll newR = r + direction[i].first;
		ll newC = c + direction[i].second;
		if(newR >= 0 && newR < adj.size() && newC >= 0 && newC < adj[r].size()) {
			if(adj[newR][newC].second == 0 && adj[newR][newC].first == 1) {
				adj[newR][newC].second == 1;
				dfs(adj, newR, newC);
			}
		}
	}
}

ll solve(vector<vector<pair<ll, ll>>>&adj) {
	ll ans = 0;
	for(ll i = 0; i < adj.size(); i++) {
		for(ll j = 0; j < adj[i].size(); j++) {
			if(adj[i][j].first == 1 && adj[i][j].second == 0) {
				ans++;
				adj[i][j].second == 1;
				dfs(adj, i, j);
			}
		}
	}
	return ans;
}

int main() {
	ll n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll>>>adj(n);
	for(ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(ll j = 0; j < m; j++) {
			char ch = s[j];
			if(ch == '#') adj[i].push_back({0, 0});
			else adj[i].push_back({1, 0});
		}
	}
	
	ll ans = solve(adj);
	cout << ans << endl;
	
	// for(ll i = 0; i < n; i++) {
	// 	for(ll j = 0; j < m; j++) 
	// 		cout << adj[i][j].first << " ";
	// 	cout << endl;
	// }
}
