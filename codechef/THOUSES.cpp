/* 
   Codechef May Long Challenge 2021
   THOUSES
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;

ll dfs(vector<vector<ll>>&adj, vector<ll>&visited, ll u) {
    if(u != 0 && adj[u].size() == 1) { // leaf node
        return 1;
    }
    
    vector<ll>b;
    for(ll i = 0; i < adj[u].size(); i++) {
        if(visited[adj[u][i]] == 1)
            continue;
        visited[adj[u][i]] = 1;
        b.push_back(dfs(adj, visited, adj[u][i]));
        
    }
    
    
    sort(b.rbegin(), b.rend());
    ll sum = 0;
    for(ll i = 0; i < b.size(); i++) {
        sum = sum + (i+1)*b[i];
    }
    return sum+1;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, x;
        cin >> n >> x;
        vector<vector<ll>>adj(n);
        for(ll i = 0; i < n-1; i++) {
            ll u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<ll>visited(n, 0);
        visited[0] = 1;
        ll ans = dfs(adj, visited, 0);
        ans = ans % mod;
        ans = (ans * x) % mod;
        cout << ans << endl;
    }
}
