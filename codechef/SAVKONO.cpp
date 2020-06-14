//SAVKONO
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main () {
    ll t, n, z;
    ll temp;
    cin >> t;
    while(t--) {
        cin >> n >> z;
        priority_queue<ll>p;
        for(ll i = 0; i < n; i++) {
            cin >> temp;
            p.push(temp);
        }
        ll count = 0;
        while(z > 0 && p.top() > 0) {
            count++;
            z -= p.top();
            temp = p.top();
            p.pop();
            p.push(temp/2);
        }
        if(z <= 0) 
            cout << count << endl;
        else 
            cout << "Evacuate" << endl;
    }
    return 0;
}
