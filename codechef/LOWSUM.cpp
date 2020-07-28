//LOWSUM
// Binary search
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, k, q, Q; 
vector<ll>A;
vector<ll>B;

ll functionOfX(ll x) {
    ll count = 0;
    for(ll i = 0; i < k; i++) {
        ll b = x - A[i];
        ll ind = upper_bound(B.begin(), B.end(), b) - B.begin();
        count += ind;
        if(ind == 0)
            break;
        // cout << "*";
    }
    return count;
}


ll minimizeX(ll low, ll high) {
    ll mid;
    while(low < high) {
        mid = low + (high - low)/2;
        ll count = functionOfX(mid);
        if(count < 10001)
            low = mid + 1;
        if(count >= 10001)
            high = mid;    
    }
    return mid;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> k >> Q;
        vector<ll>C;
        A.resize(k);
        B.resize(k);
        for(ll i = 0; i < k; i++)
            cin >> A[i];
        for(ll i = 0; i < k; i++) 
            cin >> B[i];
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        ll sum = minimizeX(A[0] + B[0], A[k-1] + B[k-1]);
        //precompute
        ll lim_j = k;
        for(ll i = 0; i < k; i++) {
            for(ll j = 0; j < lim_j; j++) {
                if(A[i] + B[j] <= sum)
                    C.push_back(A[i] + B[j]);
                else {
                    lim_j = j+1;
                    break;
                }
            }
        }
        sort(C.begin(), C.end());
        while(Q--) {
            cin >> q;
            cout << C[q-1] <<endl;
        }
    }
}
