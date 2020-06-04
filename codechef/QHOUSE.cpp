//QHOUSE
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main () {
    ll s = 0, t = 0, b = 0;
    ll l, r, m;
    string res;
    // find size of square
    l = 0;
    r = 500;
    while(l <= r) {
        m = l + (r - l) / 2;
        //check for mid value
        cout << "? " << m << " " << 0 << endl << flush;
        cin >> res;
        if(res == "YES") {
            s = max(m, s);
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    
    // find t, top of iso triangle
    l = 2 * s;
    r = 1000;
    while(l <= r) {
        m = l + (r - l) / 2;
        //check for mid value
        cout << "? " << 0 << " " << m << endl << flush;
        cin >> res;
        if(res == "YES") {
            t = max(m, t);
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    
    // find b, base of triangle
    l = s;
    r = 1000;
    while(l <= r) {
        m = l + (r - l) / 2;
        //check for mid value
        cout << "? " << m << " " << 2 * s << endl << flush;
        cin >> res;
        if(res == "YES") {
            b = max(m, b);
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    
    //calculate the area
    ll area = (2*s)*(2*s) + (b) * (t - 2 * s);
    cout << "! " << area << endl << flush;
    return 0;
}



