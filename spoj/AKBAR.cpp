#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll t;
	cin >> t;
	while(t--) {
		ll n, r, m;
		cin >> n >> r >> m;
		vector<vector<ll>>adj(n+1);
		vector<ll>check(n+1, 0);
		// adj list
		for(ll i = 0; i < r; i++) {
			ll a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		// m lines
		int flag = 0;
		for(ll i = 0; i < m; i++) {
			ll a, b;
			cin >> a >> b;
            if(check[a] != 0 && check[a] != a){
                flag = 1;
                break;
            }
            else {
			    check[a] = a;
            }
			if(b > 0) {
				queue<ll>q;
				q.push(a);
				q.push(-1);
				while(!q.empty() && b > 0) {
					ll v = q.front();
					if(v == -1) {
						b--;
                        if(b == 0)
                            break;
						q.pop();
						q.push(-1);
                        v = q.front();
					}
					else 
    					q.pop();
					for(ll i = 0; i < adj[v].size(); i++) {
						if(check[adj[v][i]] != 0 && check[adj[v][i]] != a) {
							flag = 1;
							break;	
						}
                        else if(check[adj[v][i]] == 0) {
                            check[adj[v][i]] = a;
                            q.push(adj[v][i]);
                        }
					}
                    if(flag == 1)
                        break;
				}
                if(flag == 1)
                    break;
			}
		}
		if(flag == 1) 
			cout << "No" << endl;
		else {
			ll i;
			for(i = 1; i < n+1; i++) {
				if(check[i] == 0) {
					cout << "No" << endl;
					break;
				}
			}
			if(i == n+1)
				cout << "Yes" << endl;
		}
	}
}