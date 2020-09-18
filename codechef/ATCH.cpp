#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        ll ar[n];
        for(ll i = 0; i < n; i++)
            cin >> ar[i];
        unordered_map<ll, ll>mp;
        ll smal = 0;
        ll arMax = ar[0];
        ll prevMax = ar[0];
        mp.insert({arMax, smal});
        for(ll i = 1; i < n; i++) {
            if(prevMax + ar[i] >= ar[i]) {
                arMax = max(arMax, prevMax+ar[i]);
                smal = min(smal, ar[i]);
                if(arMax == prevMax + ar[i]) {
                    if(mp.find(prevMax + ar[i]) == mp.end()) {
                        mp.insert({prevMax + ar[i], smal});
                    }
                    else {
                        if(mp[prevMax + ar[i]] > smal)
                            mp[prevMax + ar[i]] = smal;
                    }
                }
                prevMax += ar[i];
            }
            else {
                smal = 0;
                prevMax = ar[i];
                arMax = max(arMax, ar[i]);
                if(arMax == ar[i])
                    mp.insert({prevMax, smal});
            }
        }
        cout << arMax - mp[arMax] << endl;
    }
}
