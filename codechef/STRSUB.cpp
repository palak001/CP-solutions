//STRSUB
//#binary search
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>a, b;
vector<ll>ans;
vector<char>S;
ll T, N, K, Q;

bool solve(ll l, ll r, ll which) {
    if(which == 1) {
        if(a[r] - a[l-1] <= K)
            return true;
        else return false;
    }
    else if(which == 2) {
        if(b[r] - b[l-1] <= K)
            return true;
        else return false;
    }
}

ll binSearch(ll start, ll low, ll high, ll which) {
    ll mid;
    while(low <= high) {
        mid = low + (high - low)/2;
        if(solve(start, mid, which))
            low = mid + 1;
        else high = mid - 1;
    }
    return high;
}

int main () {
    cin >> T;
    while(T--) {
        a.clear();
        b.clear();
        ans.clear();
        S.clear();
        cin >> N >> K >> Q;
        S.push_back('$');
        for(ll i = 1; i <= N; i++) {
            char ch;
            cin >> ch;
            S.push_back(ch);
        }
        a.push_back(0);
        b.push_back(0);
        ans.push_back(1);
        for(ll i = 1; i <= N; i++) {
            if(S[i] == '0') {
                a.push_back(a[a.size()-1]+1);
                b.push_back(b[b.size()-1]);
            }
            else {
                b.push_back(b[b.size()-1]+1);
                a.push_back(a[a.size()-1]);
            }
        }
        ll ind1, ind2;
        for(ll i = 1; i <= N; i++) {
            ind1 = binSearch(i, ans[ans.size()-1], N, 1);
            ind2 = binSearch(i, ans[ans.size()-1], N, 2);
            ans.push_back(min(ind1, ind2));
        }
        // precompute sum of ans
        vector<ll>sumAns;
        sumAns.push_back(0);
        for(ll i = 1; i <= N; i++) {
            sumAns.push_back(sumAns[sumAns.size() - 1] + ans[i]);
        }
        // ans ready :D
        while (Q--) {
            ll l, r;
            cin >> l >> r;
            ll sum = 0;
            ll k = upper_bound(ans.begin()+l, ans.end(), r) - ans.begin();
            // for(ll i = l; i < k; i++) {
            //     sum += ans[i];
            // }
            sum = sumAns[k-1]-sumAns[l-1];
            // for(ll i = k; i <= r; i++)
            //     sum += r;
            
            sum += -1*(r*(r+1)/2 - (l-1)*l/2) + (r - l + 1) + r*(r-k+1);
                
            cout << sum << endl;
        }
    }
}
