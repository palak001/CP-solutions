#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        ll pairs = 0;
        ll mat[n][m];
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        for(ll i = 0; i < n-1; i++) {
            for(ll j = 0; j < m-1; j++) {
                if(mat[i][j] != mat[i+1][j+1])
                    pairs++;
            }
        }
        ll q;
        cin >> q;
        while(q--) {
            ll x, y, v;
            cin >> x >> y >> v;
            x--; y--;
            if(x == n-1 || y == m-1 || x == 0 || y == 0) {
                // cout << "Were you here?" << endl;
                if(x == n-1 && y != 0 || (y == m-1 && x != 0)) {
                    if(v != mat[x-1][y-1] && mat[x][y] == mat[x-1][y-1])
                        pairs++;
                    else if(v == mat[x-1][y-1] && mat[x][y] != mat[x-1][y-1])
                        pairs--;
                }    
                else if(x == 0 && y != m-1 || (y == 0 && x != n-1)) {
                    if(mat[x][y] != mat[x+1][y+1] && v == mat[x+1][y+1])
                        pairs--;
                    else if(mat[x][y] == mat[x+1][y+1] && v != mat[x+1][y+1])
                        pairs++;
                }
            }
            else {
                if(mat[x][y] != mat[x-1][y-1] && v == mat[x-1][y-1])
                    pairs--;
                else if(mat[x][y] == mat[x-1][y-1] && v != mat[x-1][y-1])
                    pairs++;
                if(mat[x][y] != mat[x+1][y+1] && v == mat[x+1][y+1])
                        pairs--;
                else if(mat[x][y] == mat[x+1][y+1] && v != mat[x+1][y+1])
                    pairs++;
            }
            mat[x][y] = v;
            // cout << "pairs: " << pairs << endl;
            if(pairs == 0)
                cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
