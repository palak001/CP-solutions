#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
ll mat[1005][1005];
ll visited[1005][1005];
vector<pair<ll, ll>>components;

/* first : numbers of banks 
   second: strength */

bool comp(pair<ll, ll>a, pair<ll, ll>b) {
    if(a.first != b.first)
        return a.first > b.first;
    else 
        return a.second < b.second;
}

void dfs_visit(ll u, ll v) {
    visited[u][v] = 1;
    components[components.size()-1].first++;
    if(v+1 < m) {
        if(mat[u][v+1] == mat[u][v] && visited[u][v+1] == 0) {
            dfs_visit(u, v+1);
        }
    }
    if(u+1 < n) {
        if(mat[u+1][v] == mat[u][v] && visited[u+1][v] == 0) {
            dfs_visit(u+1, v);
        }
    }
    if(v-1 >= 0) {
        if(mat[u][v-1] == mat[u][v] && visited[u][v-1] == 0) {
            dfs_visit(u, v-1);
        }
    }
    if(u-1 >= 0) {
        if(mat[u-1][v] == mat[u][v] && visited[u-1][v] == 0) {
            dfs_visit(u-1, v);
        }
    }
}

void dfs() {
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(!visited[i][j]) {
                // cout << "mat: " << mat[i][j] << endl;
                components.push_back({0, mat[i][j]});
                dfs_visit(i, j);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            visited[i][j] = 0;
            ll strength;
            cin >> strength;
            mat[i][j] = strength;
        }
    }
    dfs();
    sort(components.begin(), components.end(), comp);
    // cout << components.size() << endl;
    // for(ll i = 0; i < components.size(); i++) {
    //     cout << components[i].second << " " << components[i].first << endl;
    // }
    // cout << endl;
    cout << components[0].second << " " << components[0].first << endl;
    
}
