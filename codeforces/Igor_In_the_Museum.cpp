#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m, k, i;
char s[1001][1001] = {};
ll countHistory[100001]; // previous queries answer. 
ll visited[1001][1001]; 
ll x, y, ans;


void countPaintings(ll x, ll y) {
	if(x == n+1 || y == m+1 || x == 0 || y == 0)
		return;
	if(s[x][y] == '*') {
		ans++;
		return;
	}
	if(visited[x][y]!=0)
		return;
	visited[x][y] = i;
	countPaintings(x, y+1);
	countPaintings(x+1, y);
	countPaintings(x-1, y);
	countPaintings(x, y-1);
	return;
}

int main () {
	cin >> n >> m >> k;
	for(i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) 
			cin >> s[i][j]; 
	}
	
	for(i = 1; i <= k; i++) {
		cin >> x >> y;
		ans = 0;
		if(!visited[x][y]) 
			countPaintings(x, y);
		else
			ans = countHistory[visited[x][y]];
		cout << ans << endl;
		countHistory[i] = ans;
	}
	return 0;
}
