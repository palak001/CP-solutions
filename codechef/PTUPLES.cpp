#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000000
ll isPrime[N];
vector<pair<ll, ll>>ans;
vector<ll> pr;

void precompute() {

    for(ll i = 2;  i < N; i++) {
        if(isPrime[i] == 0) {
            pr.push_back(i);
            // cout << "prime: " << i  << " " << isPrime[i]<< endl;
            for(ll j = i*i; j < N; j+=i) {
                // cout << "j: " << j << endl;
                isPrime[j] = 1;
            }
        }
    }
    // cout << pr.size() << endl;
	ans.push_back({2, 0});
	ans.push_back({3, 0});
	ans.push_back({5, 1});
	
	for(ll i = 3; i < pr.size(); i++) {
		ans.push_back({pr[i], ans[ans.size()-1].second});
		ll check = ans[ans.size()-1].first - 2;
// 		cout << "check: " << check << endl;
		if(isPrime[check] == 0 && check != 2)
		    ans[ans.size()-1].second++;
	}
}



int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	precompute();
    ll t;
    cin >> t;
    while(t--) {
    	ll n;
    	cin >> n;
    	pair<ll, ll>p = {n, 0};
    	ll ind = lower_bound(ans.begin(), ans.end(), p) - ans.begin();
    // 	cout << ind << endl;
    	if(ans[ind].first != n)	--ind;
    	cout << ans[ind].second << "\n";
    }
}
