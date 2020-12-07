#include<bits/stdc++.h>
using namespace std;

int n, m;
int ans = 0;
int howManyCats = 0;

void dfs(int s, int prev, pair<int, int> visited[], map<int, int>&cats, vector<vector<int>>&adj) {
	if(visited[s].first) return;
	visited[s].first = 1;
	if(prev != 0) {
		if(cats[s] == 0) {
			if(visited[prev].second > m) 
				visited[s].second = visited[prev].second;
			else 
				visited[s].second = 0;
		}
		else visited[s].second = visited[prev].second + 1;
	}
	for(auto u:adj[s]) {
		if(visited[u].first == 0) {
			dfs(u, s, visited, cats, adj);
		}
	}
	if(adj[s].size() == 1 && visited[adj[s][0]].first == 1 && s != 1) {
		if(visited[s].second <= m) ans++;
	}
}

int main() {
	cin >> n >> m;
	map<int, int>cats;
	vector<vector<int>>adj(n+1);
	pair<int, int> visited[n+1];
	for(int i = 0; i < n+1; i++) visited[i] = {0, 0};
	for(int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		cats[i+1] = temp;
	}
	for(int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	if(cats[1] == 0)
		visited[1] = {0, 0};
	else
		visited[1] = {0, 1};
	dfs(1, 0, visited, cats, adj);	
	cout << ans << endl;
}
