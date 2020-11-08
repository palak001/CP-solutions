#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;

ll t, n, m;

void dfs_visit(vector<vector<ll>>&adj, vector<ll>&used, vector<ll>&components, ll u) {
    used[u] = 1;
    components[components.size()-1]++;
    for(ll i = 0; i < adj[u].size(); i++) {
        if(!used[adj[u][i]]) {
            dfs_visit(adj, used, components, adj[u][i]);    
        }    
    }
}

void dfs(vector<vector<ll>>&adj, vector<ll>&used, vector<ll>&components) {
    for(ll i = 1; i <= n; i++) {
        if(used[i] == 0) {
            components.push_back(0);
            dfs_visit(adj, used, components, i);
        }
    }
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vector<vector<ll>>adj(n+1);
        vector<ll>used(n+1, 0);
        vector<ll>components;
        // cout << "*" << endl;
        for(ll i = 0; i < m; i++) {
            ll u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // for(ll i = 0; i <= n; i++) {
        //     cout << i << " : ";
        //     for(ll j = 0; j < adj[i].size(); j++) 
        //         cout << adj[i][j] << " ";
        //     cout << endl;
        // }
        // cout << "*" << endl;
        dfs(adj, used, components);
        ll captians = 1;
        for(ll i = 0; i < components.size(); i++) {
            captians = (captians % mod * components[i] % mod) % mod;
        }
        cout << components.size() << " " << captians << endl;
    }
}
