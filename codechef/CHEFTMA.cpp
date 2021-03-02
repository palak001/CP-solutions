#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, k, m;
        cin >> n >> k >> m;
        vector<ll>A(n);
        for(ll i = 0; i < n; i++)
            cin >> A[i];
        vector<ll>B(n);
        for(ll i = 0; i < n; i++) 
            cin >> B[i];
        vector<ll>leftWork(n);
        ll totWork = 0;
        for(ll i = 0; i < n; i++) {
            leftWork[i] = A[i] - B[i];
            totWork += leftWork[i];
        }
        vector<ll>CD(k+m);
        for(ll i = 0; i < k+m; i++) cin >> CD[i];
        sort(CD.rbegin(), CD.rend());
        sort(leftWork.rbegin(), leftWork.rend());
        ll ans = totWork;
        ll j = 0;
        for(ll i = 0; i < leftWork.size(); i++) {
            while(CD[j] > leftWork[i]) {
                j++;
                if(j >= CD.size())
                    break;
            }
            // cout << "j: " << j << endl;
            ans -= CD[j];
            j++;
            if(j >= CD.size()) break;
        }
        cout << ans << endl;
    }
}
