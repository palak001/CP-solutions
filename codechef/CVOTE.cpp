//CVOTE - Chef of the Year 
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool comp(pair<string, int>& a, pair<string, int>& b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    else
        return a.second > b.second;
}

int main () {
    ll n, m;
    string countryName, chefName;
    unordered_map<string, string>mp1;
    unordered_map<string, int>mp2;
    unordered_map<string, int>mp3;
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        cin >> chefName >> countryName;
        mp1.insert(make_pair(chefName, countryName));
        mp2.insert(make_pair(countryName, 0));
        mp3.insert(make_pair(chefName, 0));
    }
    for(ll i = 0; i < m; i++) {
        cin >> chefName;
        mp2[mp1[chefName]]++;
        mp3[chefName]++;
    }
    
    vector<pair<string, int> >v1;
    vector<pair<string, int> >v2;
    for (auto& it : mp2) { 
        v1.push_back(it); 
    } 
    sort(v1.begin(), v1.end(), comp);
    cout << (*v1.begin()).first << endl;
    
    for (auto& it : mp3) { 
        v2.push_back(it); 
    } 
    sort(v2.begin(), v2.end(), comp);
    cout << (*v2.begin()).first << endl;
    
}
