// TEST - Life, the Universe, and Everything
#include<bits/stdc++.h>
using namespace std;

int main () {
	int n;
	int flag = 0;
	while(cin >> n) {
		if(n == 42) {
			flag = 1;
		}
		if(flag == 0) {
			cout << n << "\n";
		}
	}
}
