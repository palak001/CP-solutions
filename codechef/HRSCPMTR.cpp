#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        ll mat[n][m];
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        
        vector<multiset<ll>>set(n+m-1);
        ll k = n-1;
        for(ll i = 0; i < m; i++, k++) {
            ll a = 0, b = i;
            while(a < n && b < m) {
                set[k].insert(mat[a][b]);
                a++; b++;
            }
        }
        
        k = n-2;
        for(ll i = 1; i < n; i++, k--) {
            ll a = i, b = 0;
            while(a < n && b < m) {
                set[k].insert(mat[a][b]);
                a++; b++;
            }
        }
        
        ll q;
        cin >> q;
        ll check1, check2;
        map<int, int>record;
        for(ll i = 0; i < n+m-1; i++) {
            if(set[i].size() != set[i].count(*(set[i].begin()))) {
                record[i] = 1;
                cout << "i: " << i << endl;
            }
        }
        
        while(q--) {
            ll x, y, v;
            cin >> x >> y >> v;
            x--; y--;
            ll tempX = x, tempY = y;
            ll ind;
            if(x < y) {
                tempY = tempY - tempX;
                tempX = 0;
                ind = n-1+tempY;
                set[ind].erase(set[ind].find(mat[x][y]));
                set[ind].insert(v);
            }
            else if(x == y) {
                tempX = tempY = 0;
                ind = n - 1;
                set[ind].erase(set[ind].find(mat[x][y]));
                set[ind].insert(v);
                
            }
            else {
                tempX = tempX - tempY;
                tempY = 0;
                ind = abs(tempX - (n-1));
                set[ind].erase(set[ind].find(mat[x][y]));
                set[ind].insert(v);
            }
            mat[x][y] = v;

            if(set[ind].size() != set[ind].count(*(set[ind].begin()))) {
                cout << "No" << endl;
                record.insert({ind, 1});
            }
            else {
                if(record.size() == 0)
                    cout << "Yes" << endl;
                else if(record.size() == 1 && record[ind] == 1) {
                    cout << "Yes" << endl;
                    record.erase(ind);
                }
                else {
                    cout << "No" << endl;
                    record.erase(ind);
                }
            }
        }
    }
}
