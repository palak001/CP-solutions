#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<ll>helper;

ll dfs_visit(ll k, vector<vector<ll>>&adj, ll ar[]) {
    ll nakama = ar[k]; 
    helper[k] = 1;
    for(ll i = 0; i < adj[k].size(); i++) {
        if(helper[adj[k][i]] == 0) {
            nakama += dfs_visit(adj[k][i], adj, ar);
        }
    }
    // cout << "K: " << k << endl;
    // cout << "ar[k]: " << ar[k] << endl;
    // cout << "nakama: " << nakama << endl;
    // cout << endl;
    return ar[k] = nakama;
}

void dfs(ll ar[], vector<vector<ll>>&adj) {
    ll nakama = ar[1];
    helper[1] = 1; 
    for(ll j = 0; j < adj[1].size(); j++) {
        nakama += dfs_visit(adj[1][j], adj, ar);
    }
    ar[1] = nakama;
}

int main() {
    cin >> n;
    helper.resize(n+1, 0);
    vector<vector<ll>>adj(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll ar[n+1];
    for(ll i = 1; i <= n; i++) 
        cin >> ar[i];
    dfs(ar, adj);
    // for(ll i = 1; i <= n; i++)
    //     cout << ar[i] << " ";
    // cout << endl;
    sort(ar, ar+n+1);
    ll ans = abs(ar[2] - ar[1]);
    for(ll i = 2; i < n; i++) {
        ans = min(ans, abs(ar[i+1] - ar[i]));   
    }
    cout << ans << endl;
}
