#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll Game[n];
        for(ll i = 0; i < n; i++) {
            cin >> Game[i];
        }
        // find length of largest 0 sequence
        ll maxSeq = 0;
        ll len = 0, secSeq = 0;
        vector<ll>v;
        for(ll i = 0; i < n; i++) {
            if(Game[i] == 0) {
                len += 1;
            }    
            else {
                v.push_back(len);
                len = 0;
            }
        }
        v.push_back(0);
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        maxSeq = v[0];
        if(v.size() >= 2)
            secSeq = v[1];
        else secSeq = 0;

        if(ceil(maxSeq / 2.0) > secSeq) {
            if(maxSeq % 2 == 1)
                cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else cout << "No" << endl;
        // if(count > 0) 
        //     cout << "No" << endl;
        // else if(maxSeq % 2 == 1)
        //     cout << "Yes" << endl;
        // else 
        //     cout << "No" << endl;
    }
}
