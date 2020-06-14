//DPAIRS
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool comp(pair<ll, ll>p1, pair<ll, ll>p2) {
	return p1.first < p2.first;
}

int main () {
	ll n, m, temp;
	cin >> n >> m;
	vector<pair<ll, ll> >N;
	vector<pair<ll, ll> >M;
	for(ll i = 0; i < n; i++) {
		cin >> temp;
		N.push_back({temp, i});
	}
	for(ll i = 0; i < m; i++) {
		cin >> temp;
		M.push_back({temp, i});
	}
	
	//comparator
	sort(N.begin(), N.end(), comp);
	sort(M.begin(), M.end(), comp);
	
	if(n > m) {
    	for(ll i = 0; i < n; i++) {
    	    cout << N[i].second << " " << M[0].second << endl;
    	}
    	if(m-1 != 0) {
    	   	for(ll i = 1; i < m; i++) {
        	    cout << N[i].second << " " << M[m - 1].second << endl;
        	}   
    	}
	}
	else {
		for(ll i = 0; i < m; i++) {
    	    cout << N[0].second << " " << M[i].second << endl;
    	}
    	if(n-1 != 0) {
    	   	for(ll i = 1; i < m; i++) {
        	    cout << N[n-1].second << " " << M[i].second << endl;
        	}   
    	}
    	    
	}
		
	return 0;
}
