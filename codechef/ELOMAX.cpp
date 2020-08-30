#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    ll t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        ll ans = 0;
        ll init[n];
        ll rating[n][m], ranks[n][m];
        
        //initial rating
        for(ll i = 0; i < n; i++)
            cin >> init[i];
        
        // storing ratings
        ll change;
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                cin >> change;
                init[i] += change;
                rating[i][j] = init[i]; // rating of ith person in jth month
            }
        }
        
        // storing ranks
        for(ll j = 0; j < m; j++) {
            // rating, person
            pair<ll, ll>vals[n]; // store rating for a particular month for all n people
            for(ll i = 0; i < n; i++) {
                vals[i] = {rating[i][j], i};
            }
            sort(vals, vals + n);
            reverse(vals, vals + n);
            
            // storing ranks
            ll r = 1;
            ranks[vals[0].second][j] = r;
            for(ll i = 1; i < n; i++) {
                if(vals[i].first != vals[i-1].first) {
                  ranks[vals[i].second][j] = i+1;
                  r = i+1;
                }
                else {
                    ranks[vals[i].second][j] = r;
                }
            }
        }
        // calculate best ranking and best rating month
        
        // best rating
        for(ll i = 0; i < n; i++) {
            ll best_rank= INT_MAX, best_rating= INT_MIN, rate_mon = 0, rank_mon = 0;
            for(ll j = 0; j < m; j++) {
                if(rating[i][j] > best_rating) {
                    best_rating = rating[i][j];
                    rate_mon = j;
                }
            }
            for(ll j = 0; j < m; j++) {
                if(ranks[i][j] < best_rank) {
                    best_rank = ranks[i][j];
                    rank_mon = j;
                }
            }
            if(rank_mon != rate_mon)
                ans++;
        }
        cout << ans << endl;
    }
}
