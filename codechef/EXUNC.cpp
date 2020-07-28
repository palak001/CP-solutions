 #include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 
 int main () {
    ll n, q;
    cin >> n >> q;
    vector<ll>ar(n+1);
    set<ll>s;
    for(ll i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    s.insert(1);
    for(ll i = 2; i <= n; i++) {
        if(ar[i] % ar[i-1] != 0){
            s.insert(i);    
        }
    }
    // for(auto k:s) {
    //     cout << k << " ";

    // }
    while(q--) {
        ll a, b, c;
        cin >> a;
        if(a == 1) {
            cin >> b >> c;
            ar[b] = c;
            s.insert(b);
            if(b != n)
                s.insert(b+1);
            if(b != 1 && ar[b] % ar[b-1] == 0) {
                s.erase(b);
            }
            if(b != n && ar[b+1] % ar[b] == 0) {
                s.erase(b+1);
            }
        }
        else if(a == 2) {
            cin >> b;
            auto ans = s.upper_bound(b);
            ans--;
            cout << *ans<< endl;
        }
    }
    
 }
