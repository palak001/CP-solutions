#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        ll count = 0, mat[n][m];
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        /* count violating positions */
        for(ll i = 1; i < n; i++) {
            for(ll j = 1; j < m; j++) {
                if(mat[i][j] != mat[i-1][j-1])
                    count++;
            }
        }
        
        ll q;
        cin >> q;
        while(q--) {
            ll x, y, v;
            cin >> x >> y >> v;
            x--; y--;
            ll old = mat[x][y];
            mat[x][y] = v;
            
            if(x - 1 >= 0 && y - 1 >= 0) {
                if(mat[x][y] != old && mat[x][y] == mat[x-1][y-1])
                    count--;
            }
            
            if(x + 1 < n && y + 1 < m) {
                if(mat[x][y] != old && mat[x][y] == mat[x+1][y+1])
                    count--;
            }
            
            if(x - 1 >= 0 && y - 1 >= 0) {
                if(mat[x-1][y-1] == old && mat[x][y] != mat[x-1][y-1])
                    count++;
            }
            
            if(x + 1 < n && y + 1 < m) {
                if((mat[x][y] != old) && (old == mat[x+1][y+1]))
                    count++;
            }
            
            if(count == 0)
                cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
