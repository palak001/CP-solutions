#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(ll k, vector<vector<ll>>&adj, vector<ll>&visited) {
	for(ll i = 0; i < (ll)adj[k].size(); i++) {
		if(visited[adj[k][i]] == 0) {
			visited[adj[k][i]] = 1;
			dfs(adj[k][i], adj, visited);
		}
	}	
}

vector<ll> dfs_visit(vector<vector<ll>>&adj, vector<ll>&visited) {
	vector<ll>newRoads;
	for(ll i = 1; i < (ll)adj.size(); i++) {
		if(visited[i] == 0) { // not visited
			newRoads.push_back(i);
			dfs(i, adj, visited);
		}
	}
	return newRoads;
}

int main() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>>adj(n+1);
	for(ll i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<ll>visited(n+1, 0);
	vector<ll>newRoads = dfs_visit(adj, visited);
	if(newRoads.size() > 1) {
		cout << newRoads.size() - 1<< endl;
		for(ll i = 1; i < (ll)newRoads.size(); i++) 
			cout << newRoads[i] << " " << newRoads[i-1] << endl;
	}
	else cout << 0 << endl;
}
