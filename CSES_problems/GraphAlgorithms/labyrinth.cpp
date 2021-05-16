// Still in progress.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>>direction {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<string>dir {"R", "L", "D", "U"};
vector<string>res;
vector<pair<ll, string>>answer;
ll flag = 0;
void dfs(vector<vector<ll>>&adj, vector<vector<ll>>&visited, pair<ll, ll> indexA, pair<ll, ll> indexB, ll r, ll c) {
	// cout << "r: " << r;
	// cout << " c: " << c << endl;
	for(ll i = 0; i < direction.size(); i++) {
		ll newR = r + direction[i].first;
		ll newC = c + direction[i].second;
		if(newR < 0 || newR >= adj.size() || newC < 0 || newC >= adj[i].size()) continue;
		// cout << "newR: " << newR << " newC: " << newC << endl;
		if(visited[newR][newC] == 0 && adj[newR][newC] == 1) {
			visited[newR][newC] = 1;
			res.push_back(dir[i]);
			// cout << dir[i] <<endl;
			if(newR == indexB.first && newC == indexB.second) {
				string s;
				for(ll p = 0; p < res.size(); p++) {
					s += res[p];
				}
				answer.push_back({res.size(), s});
				return;
			}
			dfs(adj, visited, indexA, indexB, newR, newC);
			if(flag == 0)
				res.pop_back();
		}
	}
}

void solve(vector<vector<ll>>&adj, pair<ll, ll> indexA, pair<ll, ll> indexB) {
	
	for(ll i = 0; i < direction.size(); i++) {
		ll newR = indexA.first + direction[i].first;
		ll newC = indexA.second + direction[i].second;
		if(newR < 0 || newR >= adj.size() || newC < 0 || newC >= adj[i].size()) continue;
		if(adj[newR][newC] == 0) continue;
		// cout << newR << " " << newC << endl;
		if(newR == indexB.first && newC == indexB.second) {
			// cout << dir[i];
			string s = dir[i];
			answer.push_back({1, s});
			continue;
		}
		vector<vector<ll>>visited(adj.size());
		for(ll k = 0; k < adj.size(); k++) {
			for(ll p = 0; p < adj[k].size(); p++)
				visited[k].push_back(0);
		}
		visited[indexA.first][indexA.second] = 1;
		visited[newR][newC] = 1;
		res.push_back(dir[i]);
		dfs(adj, visited, indexA, indexB, newR, newC);
		res.resize(0);
	}
}

int main() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>>adj(n);
	pair<ll, ll>indexA, indexB;
	for(ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(ll j = 0; j < m; j++) {
			char ch = s[j];
			if(ch == 'A')
				indexA = {i, j};
			if(ch == 'B')
				indexB = {i, j};
			if(ch == '#')
				adj[i].push_back(0);
			else 
				adj[i].push_back(1);
		}
	}
	// cout << "indexA: " << indexA.first << " " << indexA.second << endl;
	// cout << "indexB: " << indexB.first << " " << indexB.second << endl;
	solve(adj, indexA, indexB);
	if(answer.size() == 0)
		cout << "NO" << endl;
	else {
		sort(answer.begin(), answer.end());
		cout << "YES" << endl;
		cout << answer[0].first << endl;
		cout << answer[0].second << endl;	
	}
}
